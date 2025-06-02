import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import os

# Cargar el CSV
train_df = pd.read_csv(r"C:\Users\john-\Coding\Python\AI\C++\MNIST\mnist_test_csv\mnist_test.csv")  # Cambia la ruta si está en otro luga

# Separar etiquetas e imágenes
labels = train_df.iloc[:, 0]
images = train_df.iloc[:, 1:]

# Mostrar forma del dataset
print("Tamaño del dataset:", images.shape)

# Visualizar una imagen
def mostrar_imagen(index):
    image = images.iloc[index].values.reshape(28, 28)
    label = labels.iloc[index]
    plt.imshow(image, cmap='gray')
    plt.title(f"Etiqueta: {label}")
    plt.axis('off')
    plt.show()

# Ejemplo: mostrar la imagen número 5
for i in range(1000, 1010):
    mostrar_imagen(i)