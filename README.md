# Cub3D

My first RayCaster with miniLibX

To install minilibX:

```
sudo apt-get install -y libxext-dev && sudo apt-get install -y libxrandr-dev && sudo apt-get install -y libx11-dev && sudo apt-get install -y libbsd-dev && sudo apt-get install -y libssl-dev

cd /usr/local/man/ && sudo mkdir man1

cd ~ && git clone https://github.com/42Paris/minilibx-linux.git && cd minilibx-linux && make

sudo cp man/man1/* /usr/local/man/man1/ && sudo cp libmlx.a /usr/local/lib/ && sudo cp mlx.h /usr/local/include/ 
```

To compile this project, type

```
make
```
To execute, type
```
./Cub3D maps/mapX.cub
```
mapX.cub can be map.1.cub, map2.cub, map3.cub, map4.cub, map5.cub or any valid map.cub you created.<br>
<br>
To clean the executable file, type
```
make clean
```
To clean the executable file and the objects, type
```
make fclean
```
For more information about this project, consult the subject.pdf file. <br>

![Alt text](images/01.png?raw=true "Title")
![Alt text](images/02.png?raw=true "Title")
![Alt text](images/03.png?raw=true "Title")
