#include <stdio.h>
#include <stdlib.h>

int main(){

    printf("Welcome to the Polygon Area Calculator!\n"
           "Please first provide the number of vertices.\n"
           "Then type in the coordinates of the vertices one-by-one.\n");

    // initialize variables for number of corner points and the total area of the polygon
    int numberOfVertices;
    float area = 0.0;

    printf("\nPlease type in the number of vertices: ");
    fflush(stdin);
    scanf("%i", &numberOfVertices);

    // allocate 2 1-dimensional integer arrays on the heap for the x-, and the y-coordinates of the vertices
    // both arrays should have a length equal to numberOfVertices

    // allocate memory with malloc() for x-coordinates
    float* x_coordinates = (float*)malloc(numberOfVertices * sizeof(float));
    if(x_coordinates == NULL){
        printf("Memory allocation failed for x-coordinates\n");
        return 1;
    }

    // allocate memory with malloc() for y-coordinates
    float* y_coordinates = (float*)malloc(numberOfVertices * sizeof(float));
    if(y_coordinates == NULL){
        printf("Memory allocation failed for y-coordinates\n");
        return 1;
    }

    printf("\nPlease enter the x-, and the y-coordinates for the vertices: ");

    for(int i = 0; i <= numberOfVertices; i++){

        printf("\nEnter the %i. x-coordinate: ", i);
        fflush(stdin);
        scanf("%f", &x_coordinates[i]);

        printf("\nEnter the %i. y-coordinate: ", i);
        fflush(stdin);
        scanf("%f", &y_coordinates[i]);
    }

    for(int i = 0; i <= numberOfVertices - 1; i++){
        area = area + (x_coordinates[i] * y_coordinates[i+1] - x_coordinates[i+1] * y_coordinates[i]);
    }

    area = area / 2;

    printf("The area of the polygon is: %f", area);


    // free the allocated memory
    free(x_coordinates);
    free(y_coordinates);

    return 0;
}
