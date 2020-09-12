import sys
import numpy as np
from PIL import Image
import logging
logging.basicConfig(level=logging.DEBUG)

# USAGE:
# python3 any2img.py <in_file> <out_file>

# get command line argument
in_fname = sys.argv[1]
out_fname = sys.argv[2]

# load and convert image into grayscale
im = Image.open(in_fname).convert('L')
logging.info('{} loaded with width={} and height={} and converted into grayscale'.format(in_fname, im.size[0], im.size[1]))

# extract all pixel values
data = np.asarray(im)
logging.info('matrix of pixels with shape {}x{} read from the image'.format(data.shape[0], data.shape[1]))

# output image in txt format (suitable for your program)
np.savetxt(out_fname, data, fmt='%d')
logging.info('text file saved to {}'.format(out_fname))