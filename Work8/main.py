import cv2
import numpy as np

# Загрузка изображения
image = cv2.imread('input.jpg')

# Преобразование изображения в оттенки серого
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Применение оператора Canny для выделения границ
edges = cv2.Canny(gray, 100, 200)

# Отображение изображения с выделенными границами
cv2.imshow('Edges', edges)
cv2.waitKey(0)
cv2.destroyAllWindows()