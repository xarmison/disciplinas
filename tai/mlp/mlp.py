import time
import numpy as np
import pandas as pd
from sklearn.model_selection import train_test_split

class NeuralNetwork(object):
    """Fully-connected Multi-Layer Perceptron (MLP)"""
    def __init__(self, inputSize, hiddenSize, outputSize, epochs = 100, debug = False):
        """Metodo construtor. Define as caracteristicas da MLP"""
        self.inputSize  = inputSize
        self.hiddenSize = hiddenSize
        self.outputSize = outputSize
        self.epochs     = epochs
        self.debug      = debug

        #weights
        self.W1 = np.random.randn(self.inputSize, self.hiddenSize) 
        self.W2 = np.random.randn(self.hiddenSize, self.outputSize)

    def forward(self, X):
        """Propaga as entradas pela rede"""
        # Propaga a entrada pela rede
        self.z = np.dot(X, self.W1) # Produto escalar da entrada com a primeira matrix de pesos
        self.z2 = self.sigmoid(self.z) # Função de ativação
        self.z3 = np.dot(self.z2, self.W2) # Produto escalar da hidden layer com a segunda matrix de pesos
        return self.sigmoid(self.z3) # Função de ativação na saída 

    def sigmoid(self, x):
        """Implementa a Sigmoid como função de ativação"""
        # Função de ativação
        return 1/(1 + np.exp(-x) )

    def sigmoidPrime(self, x):
        """Implementa a derivada da Sigmoid"""
        # Derivada da sigmoid 
        return x * (1 - x)

    def backward(self, X, y, o):
        """Implementa o algoritmo de backpropagation"""

        self.o_error = y - o # Erro na saída
        self.o_delta = self.o_error * self.sigmoidPrime(o) # Aplica a derivada da função de ativação na saida e multipla pelo erro
    
        self.z2_error = self.o_delta.dot(self.W2.T) # z2_error: o quão os pesos da hidden layer contribuem para o erro na saída                                           
        self.z2_delta = self.z2_error * self.sigmoidPrime(self.z2) # Aplica a derivada da sigmoid a z2_error
                                                                
        self.W1 += X.T.dot(self.z2_delta) # Ajusta a primeira matriz de pesos (input --> hidden) 
        self.W2 += self.z2.T.dot(self.o_delta) # Ajusta a segunda matriz de pesos(hidden --> output) 

    def train(self, X, y):
        """Treina a MLP usando Backpropagation"""
        print("Tranning ...")
        start = time.clock()
        for i in range(1, self.epochs + 1): 
            if self.debug:
                print("\nEpoch: %d" % i)
                print("Loss: %f" % np.mean(np.square(y - self.forward(X)))) # Média quadratia do erro
           
            o = self.forward(X)
            self.backward(X, y, o)
        end = time.clock()

        print("Traning took {:.2f}s".format(end-start))

    def predict(self, input):
        """Realiza uma classificação"""
        return self.forward(input)
    
    def getWeights(self):
        """Retorna os vetores de peso"""
        return self.W1, self.W2

def importXorDataset():
    # Importa o dataset XOR
    dataset = pd.read_csv("/home/richard/repos/disciplinas/tai/data/xor.csv", header=None)

    # Extrai todos os rotulos
    labels = dataset.iloc[:, 2].values.astype(float).reshape(30, 1)

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
   
if __name__ == "__main__":

    print("_____ Multi-Layer Perceptron _____")
    
    train_data, test_data, train_labels, test_labels = importXorDataset()

    print("Building the network ...")
    model = NeuralNetwork(2, 4, 1, 5000, debug=False)

    model.train(train_data, train_labels)

    print("MLP preditions:")
    for i, item in enumerate(test_data):
        print("Prediction for {:12} is {:12}, expected {}".format(
                np.array_str(item), np.array_str(model.predict(item)), test_labels[i] 
            )
        )
 
