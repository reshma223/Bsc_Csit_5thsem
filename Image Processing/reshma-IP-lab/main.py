import numpy as np
import cv2
img=cv2.imread('pklogo.jpg',0)
w,h=img.shape
neg_img=np.array(img)
for x in range(w):
    for y in range(h):
        neg_img[x,y]=255-img[x,y]
cv2.imshow('original',img)
cv2.imshow('neg',neg_img)
cv2.waitKey(0)
cv2.destroyAllWindows()

