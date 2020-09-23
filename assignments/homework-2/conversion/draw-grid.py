import sys
import numpy as np
from PIL import Image, ImageDraw

def draw_grid(fname, max_w):
    grid = np.loadtxt(fname, dtype=int)
    w, h = max_w, int(max_w/(grid.shape[1]/grid.shape[0]))
    cols = np.linspace(0, w-1, grid.shape[1]+1)
    rows = np.linspace(0, h-1, grid.shape[0]+1)
    img = Image.new('L', size=(w,h), color=255)
    draw = ImageDraw.Draw(img)
    for i in range(grid.shape[0]):
        for j in range(grid.shape[1]):
            draw_box(cols[j], rows[i], cols[j+1], rows[i+1], grid[i,j], draw)
    img.save(fname+'.pdf')

def draw_box(x1, y1, x2, y2, val, draw):    
    if val & 8: # NORTH
        draw.line([(x1,y1),(x2,y1)], fill=0)
    if val & 4: # SOUTH
        draw.line([(x1,y2),(x2,y2)], fill=0)
    if val & 2: # EAST
        draw.line([(x2,y1),(x2,y2)], fill=0)
    if val & 1: # WEST
        draw.line([(x1,y1),(x1,y2)], fill=0)

if __name__ == "__main__":
    draw_grid(sys.argv[1], 400)