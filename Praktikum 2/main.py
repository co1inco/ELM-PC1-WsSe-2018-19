from cpp_p2 import *
import threading


DISP_WIDTH = 175
DISP_HEIGHT = 132-20
    
class drawProcess(threading.Thread):
    def __init__(self):
        self.runLoop = True
        self.redrawAll = True
        self.volt = "5.00"
        self.poti = "0001"

        self.dsp = Display()

#        self.start()

    def initVarable(self):
        self.poti=0
        self.diaWidth=0
        self.potiTxt="5.00"
        self.voltTxt = "5.00"
        
        self.gelesen_xPos = 20
        self.volt_xPos = 95
        self.num_xPos = 40
        self.text_yPos = 20
        self.dia_yPos = 80
        
    def run(self):

        while runLoop:
            if redrawAll:
                
                self.dsp.clearScreen(white2)
                self.dsp.drawRectangle(0, 0, DISP_WIDTH, DISP_HEIGHT, 0x00, 0x00, 5)

                self.gelesen = "gelesen"
                self.dsp.drawText(gelesen_xPos, text_yPos, 0x00, 0x00, 0xff, 0xff, len(gelesen), gelesen)
                self.dsp.drawRectangle(gelesen_xPos, num_xPos, gelesen_xPos + len(gelesen) * 7, 70, 0x00, 0xf8, 3)



if __name__ == '__main__':

    
    dsp = Display()

    if True:

        runMainloop = True

        cBg = white2
        cFg = black2
        
        cpotiDes = black2
        cpotiTxt = black2
        cpotiRec = red2

        cvoltDes = black2
        cvoltTxt = black2
        cvoltRec = blue2

        cdiaSide = black2
        cdiaMid  = red2

        poti=0
        diaWidth=0
        potiTxt="0000"
        voltTxt = "5.00"
        
        gelesen_xPos = 20
        volt_xPos = 95
        num_xPos = 40
        text_yPos = 20
        dia_yPos = 80

        dsp.clearScreen(cBg)
        dsp.drawRectangle(0, 0, DISP_WIDTH, DISP_HEIGHT, cFg, width=5)

        gelesen = "gelesen"
        dsp.drawText(gelesen_xPos, text_yPos, gelesen, cpotiDes, cBg)
        dsp.drawRectangle(gelesen_xPos, num_xPos, gelesen_xPos + len(gelesen) * 7, 70, cpotiRec, width=3)
	
        sVolt = "in Volt"
        dsp.drawText(volt_xPos, text_yPos, sVolt, cvoltDes, cBg)
        dsp.drawRectangle(volt_xPos, num_xPos, volt_xPos+len(sVolt) * 7, 70, cvoltRec, width=3)

        dsp.drawRectangle(gelesen_xPos, dia_yPos, volt_xPos+len(sVolt)*7, dia_yPos + 20, cdiaSide, width=4)

        while runMainloop:
            poti = dsp.getPoti()
            print(poti)
            potiTxt = "%04i" % poti
            dsp.drawText(gelesen_xPos + 14, text_yPos + 29, potiTxt, cpotiTxt, cBg)
        
            potiVolt = int(map(poti, 0, 1023, 0, 500))
            voltTxt = "%i.%02i" % (potiVolt/100, potiVolt%100)
            dsp.drawText(volt_xPos + 15, text_yPos + 29, voltTxt, cvoltTxt, cBg);

            diaWidth = int(map(poti, 0, 1023, gelesen_xPos + 4, volt_xPos + len(sVolt) * 7 - 4))
            dsp.drawRectangle(diaWidth, dia_yPos + 4 + 2, volt_xPos + len(sVolt) * 7 - 4, dia_yPos + 14, cBg)
            dsp.drawRectangle(gelesen_xPos + 4, dia_yPos + 4 + 2, diaWidth, dia_yPos + 14, cdiaMid)

        
            runMainloop = False






    
