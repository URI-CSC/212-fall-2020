import sys
import numpy as np
from PIL import Image
import logging
logging.basicConfig(level=logging.DEBUG)

# USAGE:
# python3 img2any.py <in_file> <out_file>

# get command line argument
in_fname = sys.argv[1]
out_fname = sys.argv[2]

# load values from text file and convert to image
data = np.loadtxt(in_fname, dtype='uint8')
logging.info('matrix of pixels with shape {}x{} loaded from {}'.format(data.shape[0], data.shape[1], in_fname))
im = Image.fromarray(data, 'L')
logging.info('grayscale image created with width={} and height={}'.format(im.size[0], im.size[1]))

# save image
im.save(out_fname)
logging.info('image saved to {}'.format(out_fname))