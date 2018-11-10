
def map(value, x1, x2, y1, y2):
    return (value - x1) * (y2 - y1) / (x2 - x1) + y1
    #(x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;


def hex2col(red, green, blue):
        colors = 0x0000;
        colors = colors | (int(map(red,   0, 255, 0, 31)) << 11)
        colors = colors | (int(map(green, 0, 255, 0, 63)) << 5)
        colors = colors |  int(map(blue,  0, 255, 0, 31))
        return colors

def splitColor(color):
    return int(("%04x" % color)[2:4], 0x10), int(("%04x" % color)[0:2], 0x10)

def printColor(c1, c2=-1, c3=-1):
    if c2==-1:
        print("%6x" % c1)
    elif c3==-1:
        print("%02x %02x" % (c1, c2))
    else:
        print("%02x %02x %02x" % ( c1,c2,c3))



red2 = hex2col(255,0,0)
blue2 = hex2col(0,0,255)
green2 = hex2col(0,255,0)
white2 = hex2col(255,255,255)
black2 = hex2col(0,0,0)
grey2 = hex2col(125,125,125=
