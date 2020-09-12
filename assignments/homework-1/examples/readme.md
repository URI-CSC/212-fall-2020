# Examples

Here we provide a few examples that will be used by the autograder. Folder `./imgs` contains a few sample images in common formats such as `png` or `jpg`.  

> The instructions below assume that you have a working `python3` installation with the following packages: `numpy` and `Pillow`.  If you are using `CS50 IDE` read the last section of this document.

## Converting images into the `img` format
If you want to test your program with real world images, the first step to take is to convert the image into the `img` format required by your program.  This is the format where images are just grayscale images encoded as a matrix of numbers in text mode.  The script `any2img.py` can do this conversion for you.  In the example below, the script will convert `imgs/cow.png` into `imgs/cow.img`.

```bash
$ python3 any2img.py ./imgs/cow.png ./imgs/cow.img
```

You can now inspect `./imgs/cow.img` by using the `cat` command or opening the file in the text editor:

```bash
$ cat ./imgs/cow.img
```

## Converting from `img` into common image formats 

If you want to visualize any `img` file, you can convert the raw text into any common image file format.  This will be useful to visualize what your program is doing.  The script `img2any.py` can do this conversion for you.  In the example below, the script will convert `imgs/cow.img` into `imgs/newimage.png`.  Note that the extension provided is `png`.  You can use any other extension as well, e.g. `jpg`.

```bash
$ python3 img2any.py ./imgs/cow.img ./imgs/newimage.png
```

You can now open `newimage.png` from the file browser and visualize the image.

## Using the scripts inside CS50 IDE

CS50 IDE comes with a pre-installed version of `python`.  However a few steps are necessary to install the libraries used by the scripts explained above.  **This is a one-time setup**.  Type the commands below in the terminal window and you should be all set.

```bash
$ pip3 install --upgrade pip
$ pip3 install numpy
$ pip3 install Pillow
```
