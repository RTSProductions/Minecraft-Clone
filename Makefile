build:
	clang++ *.cpp /usr/local/Cellar/glad/src/glad.c -o Minecraft -I/usr/local/Cellar/glfw/3.3.4/include/ -L/usr/local/Cellar/glfw/3.3.4/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit -I/usr/local/Cellar/glad/include/ -I/usr/local/Cellar/glm/0.9.9.8/include/ -L/usr/local/Cellar/glm/0.9.9.8/lib/ 

build-app:
	clang++ *.cpp /usr/local/Cellar/glad/src/glad.c -o Minecraft.app -I/usr/local/Cellar/glfw/3.3.4/include/ -L/usr/local/Cellar/glfw/3.3.4/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit -I/usr/local/Cellar/glad/include/ -I/usr/local/Cellar/glm/0.9.9.8/include/ -L/usr/local/Cellar/glm/0.9.9.8/lib/
