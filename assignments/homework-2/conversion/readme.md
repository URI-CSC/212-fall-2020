## Converting from a text file into a `PDF`

If you want to visualize a maze, you can convert the raw text file into a PDF.  This will be useful to visualize what your program is doing.  The script `draw-grid.py` can do this conversion for you.  In the example below, the script will automatically convert `test.txt` into `test.txt.pdf`.  You can specify any file name and the extension `.pdf` will be automatically added to the output file.

```bash
$ python3 draw-grid.py test.txt
```

After running the command above you can now open `test.txt.pdf` and visualize the image.

## Using the scripts inside CS50 IDE

CS50 IDE comes with a pre-installed version of `python`.  However a few steps are necessary to install the libraries used by the scripts explained above.  **This is a one-time setup**.  Type the commands below in the terminal window and you should be all set.

```bash
$ pip3 install --upgrade pip
$ pip3 install numpy
$ pip3 install Pillow
```
