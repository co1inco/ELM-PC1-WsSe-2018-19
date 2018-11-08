import serial

port = 'COM1'
baud = 9600


def map(value, x1, x2, y1, y2):
    return (value - x1) * (y2 - y1) / (x2 - x1) + y1
    #(x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;


def hex2col(red, green, blue):
        colors = 0b0000000000000000;
        colors = int(colors, 2) | (int(map(red,   0, 255, 0, 31), 2) << 11);
        colors = colors | (map(green, 0, 255, 0, 63) << 6);
        colors = colors |  map(blue,  0, 255, 0, 31);
        return colors
    

class serCom():
    def __init__(self, port='COM1', baud=9600, timeout=2):
        pass
        #self.ser = serial.Serial(port, baud, timeout=timeout)

    def write(self, message):
        print("Serial send: " + str(message))
        #self.ser.write(message)

    def read(self):
        return str(500).encode()
    def close(self):
        pass
        #self.close()


class Display():
    def __init__(self, port='COM1', baud=9600, timeout=2):
        self.ser = serCom(port, baud, timeout)


    def drawRectangle(self, x1, y1, x2, y2, color1, color2, width=0):
        if width > 0:
            message = ("%02x%02x%02x%02x%02x%02x%02x%02x" % (0x03, x1, y1, x2, y2, color1, color2, width)).encode()
        elif width == 0:
            message = ("%02x%02x%02x%02x%02x%02x%02x" % (0x02, x1, y1, x2, y2, color1, color2)).encode()
        self.ser.write(message)

    def drawText(self, x, y, color1, color2, color3, color4, text):
        message = ("%02x%02x%02x%02x%02x%02x%02x%02x" % (0x05, x, y, len(text), color1, color2, color3, color4)) + text
        self.ser.write(message.encode())

    def getPoti(self):
        self.ser.write("%02x" % 0x06)
        return int(self.ser.read().decode())
        
if __name__ == "__main__":
    
    dsp = Display()

    dsp.drawRectangle(5,5,10,10,0,0xf8)
    dsp.drawText(5,5, 0x00,0x00, 0xff, 0xff, "Hlihalo")
    print(dsp.getPoti())

    print(hex2col(255,0,255))



    
