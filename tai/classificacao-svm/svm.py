import cv2
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, classification_report
from sklearn.utils import shuffle

def split2d(img, cell_size, flatten=True):
    """Função para separar cada dígito da imagem"""
    h, w = img.shape[:2]

    sx, sy = cell_size

    cells = [np.hsplit(row, w//sx) for row in np.vsplit(img, h//sy)]

    cells = np.array(cells)

    if flatten:
        cells = cells.reshape(-1, sy, sx)

    return cells

def load_digits(image):
    """Função para carregar a imagem com os dígitos"""
    digits_img = cv2.imread(image, 0)

    digits = split2d(digits_img, (20, 20))
    
    labels = np.repeat(np.arange(10), len(digits)/10)
    
    return digits, labels

def deskew(img):
    """Função para alinhamento dos dígitos"""
    m = cv2.moments(img)
    if abs(m['mu02']) < 1e-2:
        # Nenhum alinhamento é necessário 
        return img.copy()

    # Calcula a inclinação com base nos momentos centrais.
    skew = m['mu11']/m['mu02']

    # Calcule a transformação afim para corrigir a assimetria.
    M = np.float32([[1, skew, -0.5 * 20 * skew], [0, 1, 0]])
    
    # Aplica a transformação
    img = cv2.warpAffine(img, M, (20, 20), flags=cv2.WARP_INVERSE_MAP | cv2.INTER_LINEAR)
    return img

def svmInit(C=12.5, gamma=0.50625):
    """Inicia o modelo svm"""
    model = cv2.ml.SVM_create()
    model.setKernel(cv2.ml.SVM_POLY)
    model.setType(cv2.ml.SVM_C_SVC)
    
    model.setGamma(gamma)
    model.setC(10)
    model.setDegree(0.6)
    
  
    return model

def svmTrain(model, train_data, train_labels, auto=False):
    """Função para o treinamento da svm"""
    if auto:
        model.trainAuto(train_data, cv2.ml.ROW_SAMPLE, train_labels)
    else:
        model.train(train_data, cv2.ml.ROW_SAMPLE, train_labels)
    return model

def svmParams(model):
    print("Kernel type: %s" % model.getKernelType())
    print("Type       : %s" % model.getType())
    print("C          : %s" % model.getC())
    print("Degree     : %s" % model.getDegree())
    print("Nu         : %s" % model.getNu())
    print("Gamma      : %s\n" % model.getGamma())

def svmPredict(model, samples):
    """Classificação usando a svm"""
    return model.predict(samples)[1].ravel()

def get_hog():
    """Cria um descritor HOG""" 
    winSize = (20,20)
    blockSize = (8,8)
    blockStride = (4,4)
    cellSize = (8,8)
    nbins = 9
    derivAperture = 1
    winSigma = -1.
    histogramNormType = 0
    L2HysThreshold = 0.2
    gammaCorrection = 1
    nlevels = 64
    signedGradient = True

    hog = cv2.HOGDescriptor(
        winSize, blockSize, blockStride, cellSize, nbins, derivAperture,
        winSigma,histogramNormType,L2HysThreshold,gammaCorrection,nlevels, 
        signedGradient
    )

    return hog

def svmEvaluate(model, samples, labels):
    pred = svmPredict(model, samples)

    print("Report: \n{}".format(classification_report(labels, pred)))

    print("Confusion Matrix: \n{}\n".format(confusion_matrix(labels, pred)))

if __name__ == '__main__':

    print("_____ SVM _____")

    print('Loading digits from digits.png ... ')
    digits, labels = load_digits('./digits.png')

    print('Shuffling data ... ')
    # Shuffle data
    rand = np.random.RandomState(10)
    shuffle = rand.permutation(len(digits))
    digits, labels = digits[shuffle], labels[shuffle]


    print('Deskewing images ... ')
    #digits_deskewed = list(map(deskew, digits))
    digits_deskewed = digits

    print('Defining HoG parameters ...')
    # HoG feature descriptor
    hog = get_hog()

    print('Calculating HoG descriptor for every image ... ')
    hog_descriptors = []
    for img in digits_deskewed:
        hog_descriptors.append(hog.compute(img))
    hog_descriptors = np.squeeze(hog_descriptors)

    print('Spliting data into training (90%) and test set (10%)... ')
    train_n=int(0.9*len(hog_descriptors))
    digits_train, digits_test = np.split(digits_deskewed, [train_n])
    hog_descriptors_train, hog_descriptors_test = np.split(hog_descriptors, [train_n])
    labels_train, labels_test = np.split(labels, [train_n])

    print('Training SVM model ...')
    model = svmInit()
    svmTrain(model, hog_descriptors_train, labels_train)

    print('SVM parameters: ')
    svmParams(model)

    print('Evaluating model ... ')
    svmEvaluate(model, hog_descriptors_test, labels_test)


