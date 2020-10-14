import matplotlib as mpl
import matplotlib.pyplot as plt
mpl.use('Agg')
import sys
from math import pi, sin, cos
DEGREES_TO_RADIANS = pi / 180
from math import isnan

def plot_coords(coords, fname, bare_plot=False):
    if bare_plot:
        # Turns off the axis markers.
        plt.axis('off')
    # Ensures equal aspect ratio.
    plt.axes().set_aspect('equal', 'datalim')
    # Converts a list of coordinates into
    # lists of X and Y values, respectively.
    X, Y = zip(*coords)
    # Draws the plot.
    plt.plot(X, Y);
    plt.savefig(fname)

def print_coords(coords):
    for (x, y) in coords:
        if isnan(x):
            print('<gap>')
        else:
            print('({:.2f}, {:.2f})'.format(x, y))

def turtle_to_coords(turtle_program, turn_amount=60):
    # The state variable tracks the current location and angle of the turtle.
    # The turtle starts at (0, 0) facing right (0 degrees).
    state = (0.0, 0.0, 0.0)

    # Throughout the turtle's journey, we "yield" its location. These coordinate
    # pairs become the path that plot_coords draws.
    yield (0.0, 0.0)

    # Loop over the program, one character at a time.
    for command in turtle_program:
        x, y, angle = state

        if command in 'F':      # Move turtle forward
            state = (x - cos(angle * DEGREES_TO_RADIANS),
                     y + sin(angle * DEGREES_TO_RADIANS),
                     angle)

            yield (state[0], state[1])

        elif command == 'B':
            state = (x + cos(angle * DEGREES_TO_RADIANS),
                     y - sin(angle * DEGREES_TO_RADIANS),
                     angle)
            yield (state[0], state[1])

        elif command == '+':     # Turn turtle clockwise without moving
            state = (x, y, angle + turn_amount)

        elif command == '-':     # Turn turtle counter-clockwise without moving
            state = (x, y, angle - turn_amount)

in_fname = sys.argv[1]
out_fname = sys.argv[2]
data = []
angle = int(sys.argv[3])

with open(in_fname, 'r') as file:
    data = file.read().replace('\n', ' ')

plot_coords(turtle_to_coords(data, angle), out_fname)
