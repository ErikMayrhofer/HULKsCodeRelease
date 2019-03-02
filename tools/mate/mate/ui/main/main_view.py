# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'main_view.ui'
#
# Created by: PyQt5 UI code generator 5.11.3
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(828, 597)
        MainWindow.setMinimumSize(QtCore.QSize(410, 246))
        MainWindow.setDockNestingEnabled(True)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setMinimumSize(QtCore.QSize(410, 115))
        self.centralwidget.setObjectName("centralwidget")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.centralwidget)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.connect_to_label = QtWidgets.QLabel(self.centralwidget)
        self.connect_to_label.setObjectName("connect_to_label")
        self.horizontalLayout.addWidget(self.connect_to_label)
        self.cbxSelectNao = QtWidgets.QComboBox(self.centralwidget)
        self.cbxSelectNao.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
        self.cbxSelectNao.setEditable(True)
        self.cbxSelectNao.setObjectName("cbxSelectNao")
        self.cbxSelectNao.addItem("")
        self.cbxSelectNao.addItem("")
        self.horizontalLayout.addWidget(self.cbxSelectNao)
        self.btnConnectNao = QtWidgets.QPushButton(self.centralwidget)
        self.btnConnectNao.setObjectName("btnConnectNao")
        self.horizontalLayout.addWidget(self.btnConnectNao)
        self.btnDisconnectNao = QtWidgets.QPushButton(self.centralwidget)
        self.btnDisconnectNao.setEnabled(False)
        self.btnDisconnectNao.setObjectName("btnDisconnectNao")
        self.horizontalLayout.addWidget(self.btnDisconnectNao)
        self.layout_label = QtWidgets.QLabel(self.centralwidget)
        self.layout_label.setObjectName("layout_label")
        self.horizontalLayout.addWidget(self.layout_label)
        self.cbxSelectLayout = QtWidgets.QComboBox(self.centralwidget)
        self.cbxSelectLayout.setMinimumSize(QtCore.QSize(0, 0))
        self.cbxSelectLayout.setEditable(True)
        self.cbxSelectLayout.setObjectName("cbxSelectLayout")
        self.horizontalLayout.addWidget(self.cbxSelectLayout)
        self.btnLoad = QtWidgets.QPushButton(self.centralwidget)
        self.btnLoad.setObjectName("btnLoad")
        self.horizontalLayout.addWidget(self.btnLoad)
        self.btnSave = QtWidgets.QPushButton(self.centralwidget)
        self.btnSave.setObjectName("btnSave")
        self.horizontalLayout.addWidget(self.btnSave)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 828, 20))
        self.menubar.setObjectName("menubar")
        self.menuFile = QtWidgets.QMenu(self.menubar)
        self.menuFile.setObjectName("menuFile")
        self.menuNew = QtWidgets.QMenu(self.menubar)
        self.menuNew.setEnabled(True)
        self.menuNew.setObjectName("menuNew")
        self.menuConnection = QtWidgets.QMenu(self.menubar)
        self.menuConnection.setEnabled(False)
        self.menuConnection.setObjectName("menuConnection")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.toolBar = QtWidgets.QToolBar(MainWindow)
        self.toolBar.setMovable(False)
        self.toolBar.setObjectName("toolBar")
        MainWindow.addToolBar(QtCore.Qt.TopToolBarArea, self.toolBar)
        self.actionExit = QtWidgets.QAction(MainWindow)
        self.actionExit.setObjectName("actionExit")
        self.actionImageView = QtWidgets.QAction(MainWindow)
        self.actionImageView.setObjectName("actionImageView")
        self.actionTextView = QtWidgets.QAction(MainWindow)
        self.actionTextView.setObjectName("actionTextView")
        self.actionConfiguration = QtWidgets.QAction(MainWindow)
        self.actionConfiguration.setObjectName("actionConfiguration")
        self.actionMapView = QtWidgets.QAction(MainWindow)
        self.actionMapView.setObjectName("actionMapView")
        self.actionPlotView = QtWidgets.QAction(MainWindow)
        self.actionPlotView.setObjectName("actionPlotView")
        self.actionSave = QtWidgets.QAction(MainWindow)
        self.actionSave.setObjectName("actionSave")
        self.actionRequest_lists = QtWidgets.QAction(MainWindow)
        self.actionRequest_lists.setObjectName("actionRequest_lists")
        self.actionClose_all = QtWidgets.QAction(MainWindow)
        self.actionClose_all.setObjectName("actionClose_all")
        self.actionCameraCalib = QtWidgets.QAction(MainWindow)
        self.actionCameraCalib.setObjectName("actionCameraCalib")
        self.menuFile.addAction(self.actionSave)
        self.menuFile.addAction(self.actionClose_all)
        self.menuFile.addAction(self.actionExit)
        self.menuNew.addAction(self.actionImageView)
        self.menuNew.addAction(self.actionTextView)
        self.menuNew.addAction(self.actionConfiguration)
        self.menuNew.addAction(self.actionMapView)
        self.menuNew.addAction(self.actionPlotView)
        self.menuNew.addAction(self.actionCameraCalib)
        self.menuConnection.addAction(self.actionRequest_lists)
        self.menubar.addAction(self.menuFile.menuAction())
        self.menubar.addAction(self.menuNew.menuAction())
        self.menubar.addAction(self.menuConnection.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MATE"))
        self.connect_to_label.setText(_translate("MainWindow", "Connect to"))
        self.cbxSelectNao.setItemText(0, _translate("MainWindow", "/tmp/simrobot/robot2"))
        self.cbxSelectNao.setItemText(1, _translate("MainWindow", "localhost"))
        self.btnConnectNao.setText(_translate("MainWindow", "Connect"))
        self.btnDisconnectNao.setText(_translate("MainWindow", "Disconnect"))
        self.layout_label.setText(_translate("MainWindow", "Layout"))
        self.btnLoad.setText(_translate("MainWindow", "Load"))
        self.btnSave.setText(_translate("MainWindow", "Save"))
        self.menuFile.setTitle(_translate("MainWindow", "File"))
        self.menuNew.setTitle(_translate("MainWindow", "New"))
        self.menuConnection.setTitle(_translate("MainWindow", "Connection"))
        self.toolBar.setWindowTitle(_translate("MainWindow", "toolBar"))
        self.actionExit.setText(_translate("MainWindow", "Exit"))
        self.actionExit.setShortcut(_translate("MainWindow", "Ctrl+Q"))
        self.actionImageView.setText(_translate("MainWindow", "Image"))
        self.actionImageView.setShortcut(_translate("MainWindow", "Ctrl+I"))
        self.actionTextView.setText(_translate("MainWindow", "Text"))
        self.actionTextView.setShortcut(_translate("MainWindow", "Ctrl+T"))
        self.actionConfiguration.setText(_translate("MainWindow", "Config"))
        self.actionConfiguration.setShortcut(_translate("MainWindow", "Ctrl+C"))
        self.actionMapView.setText(_translate("MainWindow", "Map"))
        self.actionMapView.setShortcut(_translate("MainWindow", "Ctrl+M"))
        self.actionPlotView.setText(_translate("MainWindow", "Plot"))
        self.actionPlotView.setShortcut(_translate("MainWindow", "Ctrl+P"))
        self.actionSave.setText(_translate("MainWindow", "Save Layout"))
        self.actionSave.setShortcut(_translate("MainWindow", "Ctrl+S"))
        self.actionRequest_lists.setText(_translate("MainWindow", "Request lists"))
        self.actionRequest_lists.setShortcut(_translate("MainWindow", "Ctrl+Return"))
        self.actionClose_all.setText(_translate("MainWindow", "Close all"))
        self.actionClose_all.setToolTip(_translate("MainWindow", "Close all widgets"))
        self.actionClose_all.setShortcut(_translate("MainWindow", "Ctrl+Shift+Backspace"))
        self.actionCameraCalib.setText(_translate("MainWindow", "Camera Calibration"))
