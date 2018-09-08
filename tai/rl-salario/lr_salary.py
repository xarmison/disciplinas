import pandas as pd
import matplotlib.pyplot as plt
from sklearn.utils import shuffle
from sklearn import linear_model
from sklearn.metrics import mean_squared_error, r2_score

if __name__ == "__main__":
    print("_____ Linear Regression _____\n")
    salary_data = pd.read_csv("../data/salary_data.csv")

    print("Data loaded: \n%s\n" % salary_data.head())

    # Embaralha os dados para uma melhor representação no medelo
    salary_data = shuffle(salary_data)

    # Separando os dados para a variável independente e para variável dependete 
    X = salary_data.iloc[:,:-1].values
    y = salary_data.iloc[:, 1].values

    # Separa os dados para treino e teste
    X_train = X[:20, :]
    X_test = X[-10:, :]

    y_train = y[:20]
    y_test = y[-10:]

    # Cria o modelo para regressão linear
    model = linear_model.LinearRegression()

    # Treina o modelo
    model.fit(X_train, y_train)

    # Predições para os dados de teste
    y_pred = model.predict(X_test)

    # Coeficientes do modelo
    print("Coefficient: %s\n" % model.coef_)

    # Erro médio quadrado
    print("Mean squared error: %.3f" % mean_squared_error(y_test, y_pred))

    # Variância (1 classificação perfeita)
    print("Variance score: %.3f" % r2_score(y_test, y_pred))

    # Plota os resultados
    
    plt.title('Linear Regression') 
    plt.xlabel('Years of Experience')
    plt.ylabel('Salary')
        
    plt.scatter(X_test, y_test, color='red')
    plt.plot(X_test, y_pred, color='blue', linewidth=2)

    plt.tight_layout()
    plt.show()


