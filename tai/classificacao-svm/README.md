# Support Vector Machine (SVM)

Modelo SVM implementado para classificação de números escritos a mão.

## Dataset 

![alt MNIST Dataset](digits.png)

## Exemplo de saída

_____ SVM _____

Loading digits from digits.png ...

Shuffling data ...

Deskewing images ...

Defining HoG parameters ...

Calculating HoG descriptor for every image ...

Spliting data into training (90%) and test set (10%)...

Training SVM model ...

|SVM parameters|         |
|:------------ |:--------|
|Kernel type   | 1       |
|Type          | 100     |
|C             | 1.0     |
|Degree        | 0.6     |
|Nu            | 0.0     |
|Gamma         | 0.50625 |

Evaluating model ...

Report:

| class     | precision |  recall  | f1-score  | support |
|:--------: |:--------: |:--------:|:--------: |:------: |
|  0        |     1.00  |   1.00   |   1.00    |     52  |
|  1        |     1.00  |    0.96  |    0.98   |     45  |
|  2        |     0.97  |    0.97  |    0.97   |     62  |
|  3        |     1.00  |    1.00  |    1.00   |     49  |
|  4        |     0.98  |    1.00  |    0.99   |     44  |
|  5        |     0.98  |    1.00  |    0.99   |     49  |
|  6        |     1.00  |    1.00  |    1.00   |     46  |
|  7        |     0.96  |    0.96  |    0.96   |     51  |
|  8        |     1.00  |    0.98  |    0.99   |     51  |
|  9        |     0.98  |    1.00  |    0.99   |     51  |
|avg / total|     0.99  |    0.99  |    0.99   |    500  |

Confusion Matrix:

```python
[
    [52  0  0  0  0  0  0  0  0  0]
    [ 0 43  2  0  0  0  0  0  0  0]
    [ 0  0 60  0  0  0  0  2  0  0]
    [ 0  0  0 49  0  0  0  0  0  0]
    [ 0  0  0  0 44  0  0  0  0  0]
    [ 0  0  0  0  0 49  0  0  0  0]
    [ 0  0  0  0  0  0 46  0  0  0]
    [ 0  0  0  0  1  0  0 49  0  1]
    [ 0  0  0  0  0  1  0  0 50  0]
    [ 0  0  0  0  0  0  0  0  0 51]
]
```