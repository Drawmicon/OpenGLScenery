###### Using OpenGL libraries to create a simplistic scene of my University.

**Linux Commands To Compile C++ Code:
	`g++ landscape11.cpp -o land -lglut -lGLU -lGL
	./land** `
	
Using the arrow keys allow the camera to pivot within a limit.

A hedge is created by creating 100 leaves in a box form.
Each leaf is a green quad, rotated in a randomly generated direction. 
Two loops are used to create a row of leaves, and then a plane of leaves.
Then a function generates 4 planes of leaves to create a bush.

Cones are created by created a function that creates a circle, then creating another function that makes multiple cirles with decreasing radii. Cans are also created with the same circle function.

Other functions included:
-Arrow Key input function
-Simple line creating function
-Function that creates a grid using the line function
-Box and plane functions for the rest of the simple shaped objects, e.g. Buildings, grass, road

