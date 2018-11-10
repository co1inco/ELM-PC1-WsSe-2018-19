import serial
from colorLib import *
import math

port = 'COM1'
baud = 9600

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
        self.outType = "hex"

    def clearScreen(self, color1=-1, color2=-1):
        if color1 == -1:
            color1 = 0x00
            color2 = 0x00
        elif color2==-1:
            color1, color2 = splitColor(color1)

        if self.outType == "hex":
            s = "%02x%02x%02x"
        elif self.outType == "char":
            s = "%c%c%c"

        message = (s % (0x00, color1, color2)).encode()
        self.ser.write(message)


    def drawRectangle(self, x1, y1, x2, y2, color1, color2=-1, width=0):
        if width > 0:
            if self.outType == "hex":
                s = "%02x%02x%02x%02x%02x%02x%02x%02x"
            elif self.outType == "char":
                s = "%c%c%c%c%c%c%c%c"
        if width == 0:
            if self.outType == "hex":
                s = "%02x%02x%02x%02x%02x%02x%02x"
            elif self.outType == "char":
                s = "%c%c%c%c%c%c%c"
            
        if color2==-1:
            color1, color2 = splitColor(color1)
        if width > 0:
            message = (s % (0x03, x1, y1, x2, y2, color1, color2, width)).encode()
        elif width == 0:
            message = (s % (0x02, x1, y1, x2, y2, color1, color2)).encode()
        self.ser.write(message)
        

    def drawText(self, x, y, text, color1, color2, color3=-1, color4=-1):
        if self.outType == "hex":
            s = "%02x%02x%02x%02x%02x%02x%02x%02x"
        elif self.outType == "char":
            s = "%c%c%c%c%c%c%c%c"
            
        if color3==-1 or color4==-1:
            color3, color4 = splitColor(color2)
            color1, color2 = splitColor(color1)
        message = (s % (0x05, x, y, len(text), color1, color2, color3, color4)) + text
        self.ser.write(message.encode())


    def getPoti(self):
        if self.outType == "hex":
            s = "%02x"
        elif self.outType == "char":
            s = "%c"
            
        self.ser.write((s % 0x06).encode())
        return int(self.ser.read().decode())

    def drawOval(self, x1, y1, x2, y2, color1, color2=-1, width=0, keepWidth=True): 
        if color2==-1:
            color1, color2 = splitColor(color1)

        if self.outType == "hex":
            s = "%02x%02x%02x%02x%02x%02x%02x"
        elif self.outType == "char":
            s = "%c%c%c%c%c%c%c"

        if keepWidth:
            x1 = x1+(y2-y1)
            x2 = x2-(y2-y1)
            
        commands = []
        if width == 0:
            commands.append((s % (0x02, x1, y1, x2, y2, color1, color2)).encode())
            for i in range(y1, y2, 2):
                pos = round(math.sin(map(i, y1, y2, 0, math.pi))*width)
                commands.append((s % (0x02, x1-pos-2, i, x1, i+1, color1, color2)).encode())
                commands.append((s % (0x02, x2, i, x2+pos+2, i+1, color1, color2)).encode())

        else:
            commands.append((s % (0x02, x1, y1, x2, y1+width, color1, color2)).encode())
            commands.append((s % (0x02, x1, y2-width, x2, y2, color1, color2)).encode())
            for i in range(y1, y2, 2):
                pos = round(math.sin(map(i, y1, y2, 0, math.pi))*width)
                commands.append((s % (0x02, x1-pos-2, i, x1-pos, i+1, color1, color2)).encode())
                commands.append((s % (0x02, x2+pos, i, x1+pos+2, i+1, color1, color2)).encode())

        for i in commands:
            self.ser.write(i)
            
            
if __name__ == "__main__":
    
    dsp = Display()

    dsp.clearScreen()

    dsp.drawRectangle(5,5,10,10,red2)
    dsp.drawText(5,5, "Hlihalo", red2, white2)
    print(dsp.getPoti())

    dsp.drawOval(5,5,10,10,red2)
    


    
