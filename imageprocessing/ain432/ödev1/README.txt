First, I pulled the pictures from Google drive. I did unzipping. 
Then I got the pictures from the folder. 
I read the picture in grayscale and divided it into 3 equal parts according to the height. 
I recorded these 3 tracks as B,G,R. 
The roll function performs a shift operation on the array. 
I needed some functions to make these pictures I divided into three into a single picture and overlap. 
The functions that met my need were pyramid and align functions. 
The align function finds the most similar parts of the 2 pictures and returns the first index values of those parts . Then, with the roll function, we shift the array of the picture according to these points. 
The pyramid function is a align function used for pictures larger than 256. 
After that, we get our colored picture output . 
We have tried some improvement methods in this image output. These are laplacian filtering, gamma correction, and histogram equalization. 
I applied these filters to the pictures separately. Then 
I realized I was getting better results with only histogram equalization filter , and that's why I have only  used it in all the other pictures.