#Подключаем библиотеки
import numpy as np
import cv2
import time

def gaussian_blur(image, kernel_size, sigma):
    # Создание Гауссова ядра
    kernel = np.fromfunction(lambda x, y: (1/(2*np.pi*sigma**2)) * np.exp(-((x-(kernel_size[0]//2))**2 + (y-(kernel_size[1]//2))**2)/(2*sigma**2)), kernel_size)

    # Нормализация ядра
    kernel = kernel / np.sum(kernel)

    # Применение размытия
    blurred_image = np.zeros_like(image, dtype=np.float32)
    for i in range(3):  # Проход по каждому каналу изображения (RGB)
        blurred_image[:,:,i] = np.convolve(image[:,:,i].flatten(), kernel.flatten(), mode='same').reshape(image.shape[:2])

    return blurred_image.astype(np.uint8)

# Пример использования
t1 = time.time()
image = cv2.imread('input.jpg')
blurred_image = gaussian_blur(image, (5, 5), 1.5)
print("Custom time: ",time.time() - t1, "sec")
t2 = time.time()
cv_image = cv2.GaussianBlur(image, (5, 5), 1.5)
print("OpenCV time: ",time.time() - t2, "sec")
cv2.imshow('Original Image', image)
cv2.imshow('Blurred Image', blurred_image)
cv2.imshow("CV Image", cv_image)
cv2.waitKey(0)
cv2.destroyAllWindows()

