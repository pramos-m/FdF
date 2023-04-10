# FdF

First graphical project at 42 Barcelona, using the [minilibx](https://github.com/42Paris/minilibx-linux) graphics library.

>This project is a simple wireframe model representation of a 3D landscape by linking various points (x, y, z) thanks to line segments (edges). The coordinates of the landscape are stored in a .fdf file passed as a parameter to the program.

## **About:**
**Mandatory part:**
- Your program has to display the image in a window.
- The management of your window must remain smooth (changing to another window, minimizing, and so forth).
- Pressing ESC must close the window and quit the program in a clean way.
- Clicking on the cross on the window’s frame must close the window and quit the program in a clean way.
- The use of the images of the MiniLibX is mandatory

### **Example input:**
```
$>cat test.fdf
0 0 1 2 3 4 5 6 7 8 9
0 0 0 1 2 3 4 5 6 7 8
0 0 0 0 1 2 3 4 5 6 7
0 0 0 0 0 1 2 3 4 5 6
0 0 0 0 0 0 1 2 3 4 5
0 0 0 0 0 0 0 1 2 3 4
0 0 0 0 0 0 0 0 1 2 3
0 0 0 0 0 0 0 0 0 1 2
0 0 0 0 0 0 0 0 0 0 1
$>
```
**Produces the following output:**

![screenshot]()

## **Usage:**
*This program was compiled and tested on Linux.*

```shell
# Clone the repository:
$> git clone --recursive git@github.com:pramos-m/FdF.git

# Compile:
$> make

# Run with valid map as parameter:
$> ./fdf map.fdf
```


 minilib-docs -> https://harm-smits.github.io/42docs/libs/minilibx/introduction.html
 mlx-tuto-42 -> https://elearning.intra.42.fr/notions/minilibx/subnotions/mlx-introduction/videos/introduction-to-minilibx
 mlx-tuto-42 -> https://elearning.intra.42.fr/notions/minilibx/subnotions/mlx-events/videos/minilibx-events
 fdf-tuto-42 -> https://elearning.intra.42.fr/notions/fdf/subnotions/introduction-to-fdf/videos/introduction-to-fdf
 fdf-how-to -> https://github.com/nikGrape/FDF
 mlx-synopsis -> https://qst0.github.io/ft_libgfx/man_mlx_loop.html
 mlx-git -> https://github.com/qst0/ft_libgfx
 mlx-algorimh -> https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
