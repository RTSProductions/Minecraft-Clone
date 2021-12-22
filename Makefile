build:
	clang++ *.cpp -o Minecraft -I/usr/local/Cellar/glfw/3.3.4/include/ -L/usr/local/Cellar/glfw/3.3.4/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit

build-app:
	clang++ *.cpp -o Minecraft.app -I/usr/local/Cellar/glfw/3.3.4/include/ -L/usr/local/Cellar/glfw/3.3.4/lib -lglfw -framework Cocoa -framework OpenGL -framework IOKit
