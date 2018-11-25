from PyQt5.QtWidgets import *
from PyQt5.QtGui import *
#from PyQt5 import QtCore
from PyQt5.QtCore import *
from PyQt5.QtWidgets import QMessageBox

import os, os.path, sys
import webbrowser, urllib

import time, datetime
import random
import threading


file_str = "Datei"
quit_str = "Exit"
edit_str = "Edit"
help_str = "Help"

def com1(d1=None):
    print("hello")
def com2(d1=None):
    print("hello2")


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.initUI()

    def initUI(self):
        self.showStatusbar = True
        
        self.setWindowTitle("Praktikum3")

        self.initStatusbar()
        self.initMenubar()
        self.initBody()
        

        label = clock(self)
        self.statusBar().addPermanentWidget(label)
        self.show()
            

    def toggleStatusBar(self, state):
        if state:
            self.statusbar.show()
        else:
            self.statusbar.hide()
            
    def initStatusbar(self):
        self.statusbar = self.statusBar()
        self.statusBar().showMessage('Ready')

    def initMenubar(self):
        menubar = self.menuBar()

        fileMenu = menubar.addMenu("&File")
    
        impMenu = QMenu("Import", self)
        impAct  = QAction("Import something", self)
        impAct.setStatusTip("Does nothing")
        impMenu.addAction(impAct)
        impMenu.triggered.connect(lambda: print("Import"))
        fileMenu.addMenu(impMenu)
        
        exitAct = QAction(QIcon('exit.png'), 'E&xit', self)        
        exitAct.setShortcut('Ctrl+X')
        exitAct.setStatusTip('Exit application')
        exitAct.triggered.connect(qApp.quit)
        fileMenu.addAction(exitAct)
        
        viewMenu = menubar.addMenu("View")
        viewStatAct = QAction("Show Statusbar", self, checkable=True)
        viewStatAct.setStatusTip("View Statusbar")
        viewStatAct.setChecked(True)
        viewStatAct.triggered.connect(self.toggleStatusBar)
        viewMenu.addAction(viewStatAct)


    def initBody(self):
        #mainwindow does not support custom layouts (Body.initBody() content would be ok)
        self.body = Body(self)
        self.setCentralWidget(self.body)


class Body(QWidget):
    def __init__(self, parent=None):
        super().__init__()
        self.parent = parent
        self.initBodyL()

    def printTxt(text1="Test Text", text2="Txt2", text3="Txt3"):
        print(str(text1) + " " + str(text2) + " " + str(text3))
#    print(text2)
#    print(text3)
#       print("TxT")

    def initBody(self):

        QToolTip.setFont(QFont('SansSerif', 10))
        
        self.setToolTip('This is a <b>QWidget</b> widget')
        
        btn = QPushButton('Text', self)
        btn.setToolTip('This is a <b>QPushButton</b> widget')
        btn.clicked.connect(self.printTxt)
        btn.resize(btn.sizeHint())
        btn.move(5, 5+20)

        btn2 = QPushButton("Quit", self)
        btn2.clicked.connect(QApplication.instance().quit)
        btn2.resize(btn2.sizeHint())
        btn2.move(5, 30+20)

        
        textEdit = QTextEdit(self)
        textEdit.resize(200, 160)
        textEdit.move(85, 5+20)
        

    def initBodyL(self):

        hbox = QHBoxLayout(self)
        btnLayout = QVBoxLayout()
        btnLayout.setAlignment(Qt.AlignTop)
        
        QToolTip.setFont(QFont('SansSerif', 10))
        
        self.setToolTip('This is a <b>QWidget</b> widget')
        
        btn = QPushButton('Text', self)
        btn.setToolTip('This is a <b>QPushButton</b> widget')
        btn.clicked.connect(self.printTxt)
        btn.resize(btn.sizeHint())
        btnLayout.addWidget(btn)

        btn2 = QPushButton("Quit", self)
        btn2.setToolTip('Exit Application')
        btn2.clicked.connect(QApplication.instance().quit)
        btn2.resize(btn2.sizeHint())
        btnLayout.addWidget(btn2)

        hbox.addLayout(btnLayout)
        
        textEdit = QTextEdit(self)
        textEdit.resize(200, 160)
        hbox.addWidget(textEdit)

        self.setLayout(hbox)
        self.show()

class clock(QLabel):
    def __init__(self, app, timeformat="%H:%M:%S", pause=1):
        super().__init__()
        self.parent = app
        self.timeformat = timeformat
        self.pause = pause

        self.runLoop = True
        self.t = threading.Thread(target=self.loop)
        self.t.start()

    def loop(self):
        while self.runLoop:
            self.setText(datetime.datetime.now().strftime(self.timeformat))
            time.sleep(self.pause)

    def stop(self):
        self.runLoop = False


if __name__ == "__main__":
    app = QApplication(sys.argv)
    ex = MainWindow()
    os._exit(app.exec())





