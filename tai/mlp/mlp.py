from timeit import default_timer as timer
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.metrics import confusion_matrix, classification_report

class NeuralNetwork(object):
    """Fully-connected Multi-Layer Perceptron (MLP)"""
    def __init__(self, inputSize, hiddenSize, outputSize, learning_rate = 0.01, bias = 1, epochs = 100, debug = False):
        """Metodo construtor. Define as caracteristicas da MLP"""
        self.inputSize  = inputSize
        self.hiddenSize = hiddenSize
        self.outputSize = outputSize
        self.lr         = learning_rate
        self.bias       = bias
        self.epochs     = epochs
        self.debug      = debug

        #weights
        np.random.seed(1)
        self.w1 = np.random.random((self.inputSize + 1, self.hiddenSize)) 
        self.w2 = np.random.random((self.hiddenSize, self.outputSize)) 
               
    def sigmoid(self, x):
        """Implementa a Sigmoid como função de ativação"""
        # Função de ativação
        return 1/(1 + np.exp(-x) )

    def sigmoidPrime(self, x):
        """Implementa a derivada da Sigmoid"""
        # Derivada da sigmoid 
        #return np.exp(-x)/(1 + np.exp(-x))**2
        return x * (1 - x)

    def predict(self, inp):
        net1 = self.sigmoid( np.dot(inp, self.w1) )
        net2 = self.sigmoid( np.dot(net1,self.w2) )

        return net2

    def train(self, inputs, outputs):
        # Adiciona o bias no vetor de entrada
        inputs = np.hstack((inputs, np.ones((inputs.shape[0], self.bias))))

        start = timer()
        for i in range(1, self.epochs + 1): 

            l0 = inputs
            l1 = self.sigmoid(np.dot(l0, self.w1))
            l2 = self.sigmoid(np.dot(l1, self.w2))

            l2_err   = outputs - l2
            l2_delta = self.lr * np.multiply(l2_err, self.sigmoidPrime(l2))

            l1_err   = np.dot(l2_delta, self.w2.T)
            l1_delta = self.lr * np.multiply(l1_err, self.sigmoidPrime(l1))

            self.w2 += np.dot(l1.T, l2_delta)
            self.w1 += np.dot(l0.T, l1_delta)

            if self.debug:
                print("\nEpoch: {}".format(i))
                print("Error: {}".format(np.mean(np.square(l2_err))))      
        end = timer()
        print("Traning took {:.2f}s".format(end-start))
        
    def getWeights(self):
        """Retorna os vetores de peso"""
        print("\n___Weights___")

        print("(input -> hidden):\n[")
        for i in self.w1:
            print("  {:15}".format(np.array_str(i)))
        print("]\n")

        print("(hidden -> output):\n[")
        for i in self.w2:
            print("  {:15}".format(np.array_str(i)))
        print("]\n")

def importXorDataset():
    # Importa o dataset XOR
    dataset = pd.read_csv("../data/xor.csv", header=None)

    # Extrai todos os rotulos
    labels = dataset.iloc[:, 2].values.astype(float).reshape(2000, 1)

    # Extrai todos as entradas
    inputs = dataset.iloc[:, [0, 1]].values.astype(float)
   
    # Divide os dados para treinamento e teste
    train_data, test_data, train_labels, test_labels = train_test_split(
        inputs, labels, test_size = 0.1, random_state = None
    )

    return train_data, test_data, train_labels, test_labels

def importIrisDataset():
    # Importa o iris dataset
    dataset = pd.read_csv('../data/iris_data.csv', header=None)

    # Extrai os 100 primeiras rotulos 
    labels = dataset.iloc[:, 4].values.reshape(150, 1)
    
    # Substitui o nome dos rotulos 
    for i, label in enumerate(labels):
        if(label == 'Iris-setosa'):
            labels[i][0] = 0
        elif(label == 'Iris-versicolor'):
            labels[i][0] = 1
        else:
            labels[i][0] = 2

    labels.astype(int)

    # Extrai as caracteristicas das amostras
    inputs = dataset.iloc[:, [0, 1, 2, 3]].values.astype(float)

    # Divide os dados para treinamento e teste
    train_data, test_data, train_labels, test_labels = train_test_split(
        inputs, labels, test_size = 0.1, random_state = None
    )

    return train_data, test_data, train_labels, test_labels
   
def plotData(x, y, x1):
    import matplotlib.pyplot as plt

    plt.title("Data")
    plt.scatter(x[:, 0], x[:, 1], c=y.reshape(1800,))
    plt.scatter(x1[:, 0], x1[:, 1], c='green')
    plt.grid(True, which='both')
    plt.tight_layout()
    plt.show()

if __name__ == "__main__":

    print("_____ Multi-Layer Perceptron _____")
    
    print("Importing data ...")
    train_data, test_data, train_labels, test_labels = importXorDataset()

    print("Building the network ...")
    model = NeuralNetwork(2, 5, 1, learning_rate=0.01, epochs=10000, debug=False)

    print("Traning ...")
    model.train(train_data, train_labels)

    if(model.debug) :
        model.getWeights()
        
        print("MLP preditions:")
        for i, item in enumerate(test_data):
            print("Prediction for {:15} is {:3}, expected {}".format(
                    np.array_str(item), np.array_str(np.round(model.predict(np.append(item, 1)))), test_labels[i] 
                )
            )
    
    pred = np.round(model.predict(np.hstack((test_data, np.ones((test_data.shape[0], 1))))))
    print("\nReport: \n{}".format(classification_report(test_labels, pred)))
    print("Confusion Matrix: \n{}\n".format(confusion_matrix(test_labels, pred)))
    
    plotData(train_data, train_labels, test_data)    
