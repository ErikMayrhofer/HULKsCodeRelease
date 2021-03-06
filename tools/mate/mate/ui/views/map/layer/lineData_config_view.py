# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'src/mate/ui/views/map/layer/lineData_config_view.ui'
#
# Created by: PyQt5 UI code generator 5.9.2
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_LineDataConfig(object):
    def setupUi(self, LinesDataConfig):
        LinesDataConfig.setObjectName("LinesDataConfig")
        LinesDataConfig.setGeometry(QtCore.QRect(0, 0, 591, 613))
        self.verticalLayout = QtWidgets.QVBoxLayout(LinesDataConfig)
        self.verticalLayout.setObjectName("verticalLayout")
        self.scrollArea = QtWidgets.QScrollArea(LinesDataConfig)
        self.scrollArea.setFrameShape(QtWidgets.QFrame.NoFrame)
        self.scrollArea.setFrameShadow(QtWidgets.QFrame.Plain)
        self.scrollArea.setWidgetResizable(True)
        self.scrollArea.setObjectName("scrollArea")
        self.scrollAreaWidgetContents = QtWidgets.QWidget()
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, -89, 559, 654))
        self.scrollAreaWidgetContents.setObjectName("scrollAreaWidgetContents")
        self.verticalLayout_5 = QtWidgets.QVBoxLayout(self.scrollAreaWidgetContents)
        self.verticalLayout_5.setObjectName("verticalLayout_5")
        self.groupBox = QtWidgets.QGroupBox(self.scrollAreaWidgetContents)
        self.groupBox.setObjectName("groupBox")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.groupBox)
        self.verticalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        self.formLayout = QtWidgets.QFormLayout()
        self.formLayout.setContentsMargins(4, 4, 4, 4)
        self.formLayout.setObjectName("formLayout")
        self.nameLineEdit = QtWidgets.QLineEdit(self.groupBox)
        self.nameLineEdit.setObjectName("nameLineEdit")
        self.formLayout.setWidget(0, QtWidgets.QFormLayout.FieldRole, self.nameLineEdit)
        self.centerLabel = QtWidgets.QLabel(self.groupBox)
        self.centerLabel.setObjectName("centerLabel")
        self.formLayout.setWidget(1, QtWidgets.QFormLayout.LabelRole, self.centerLabel)
        self.centerWidget = QtWidgets.QWidget(self.groupBox)
        self.centerWidget.setObjectName("centerWidget")
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout(self.centerWidget)
        self.horizontalLayout_2.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        self.label_center_x = QtWidgets.QLabel(self.centerWidget)
        self.label_center_x.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_center_x.setObjectName("label_center_x")
        self.horizontalLayout_2.addWidget(self.label_center_x)
        self.spin_center_x = QtWidgets.QDoubleSpinBox(self.centerWidget)
        self.spin_center_x.setMinimum(-99.99)
        self.spin_center_x.setObjectName("spin_center_x")
        self.horizontalLayout_2.addWidget(self.spin_center_x)
        self.label_center_y = QtWidgets.QLabel(self.centerWidget)
        self.label_center_y.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_center_y.setObjectName("label_center_y")
        self.horizontalLayout_2.addWidget(self.label_center_y)
        self.spin_center_y = QtWidgets.QDoubleSpinBox(self.centerWidget)
        self.spin_center_y.setMinimum(-99.99)
        self.spin_center_y.setObjectName("spin_center_y")
        self.horizontalLayout_2.addWidget(self.spin_center_y)
        self.formLayout.setWidget(1, QtWidgets.QFormLayout.FieldRole, self.centerWidget)
        self.enabledLabel = QtWidgets.QLabel(self.groupBox)
        self.enabledLabel.setObjectName("enabledLabel")
        self.formLayout.setWidget(3, QtWidgets.QFormLayout.LabelRole, self.enabledLabel)
        self.enabledCheckBox = QtWidgets.QCheckBox(self.groupBox)
        self.enabledCheckBox.setChecked(True)
        self.enabledCheckBox.setObjectName("enabledCheckBox")
        self.formLayout.setWidget(3, QtWidgets.QFormLayout.FieldRole, self.enabledCheckBox)
        self.nameLabel = QtWidgets.QLabel(self.groupBox)
        self.nameLabel.setObjectName("nameLabel")
        self.formLayout.setWidget(0, QtWidgets.QFormLayout.LabelRole, self.nameLabel)
        self.translationLabel = QtWidgets.QLabel(self.groupBox)
        self.translationLabel.setObjectName("translationLabel")
        self.formLayout.setWidget(2, QtWidgets.QFormLayout.LabelRole, self.translationLabel)
        self.translationWidget = QtWidgets.QWidget(self.groupBox)
        self.translationWidget.setObjectName("translationWidget")
        self.verticalLayout_6 = QtWidgets.QVBoxLayout(self.translationWidget)
        self.verticalLayout_6.setObjectName("verticalLayout_6")
        self.cbx_TransformationKey = QtWidgets.QComboBox(self.translationWidget)
        self.cbx_TransformationKey.setEditable(True)
        self.cbx_TransformationKey.setObjectName("cbx_TransformationKey")
        self.verticalLayout_6.addWidget(self.cbx_TransformationKey)
        self.label_4 = QtWidgets.QLabel(self.translationWidget)
        self.label_4.setObjectName("label_4")
        self.verticalLayout_6.addWidget(self.label_4)
        self.edit_TransformationKeyLambda = QtWidgets.QTextEdit(self.translationWidget)
        self.edit_TransformationKeyLambda.setMaximumSize(QtCore.QSize(16777215, 80))
        self.edit_TransformationKeyLambda.setTabStopWidth(16)
        self.edit_TransformationKeyLambda.setObjectName("edit_TransformationKeyLambda")
        self.verticalLayout_6.addWidget(self.edit_TransformationKeyLambda)
        self.label_3 = QtWidgets.QLabel(self.translationWidget)
        self.label_3.setObjectName("label_3")
        self.verticalLayout_6.addWidget(self.label_3)
        self.formLayout.setWidget(2, QtWidgets.QFormLayout.FieldRole, self.translationWidget)
        self.verticalLayout_2.addLayout(self.formLayout)
        self.verticalLayout_5.addWidget(self.groupBox)
        self.groupBox_2 = QtWidgets.QGroupBox(self.scrollAreaWidgetContents)
        self.groupBox_2.setObjectName("groupBox_2")
        self.verticalLayout_3 = QtWidgets.QVBoxLayout(self.groupBox_2)
        self.verticalLayout_3.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        self.formLayout_2 = QtWidgets.QFormLayout()
        self.formLayout_2.setContentsMargins(4, 4, 4, 4)
        self.formLayout_2.setObjectName("formLayout_2")
        self.keyLambdaWidget = QtWidgets.QWidget(self.groupBox_2)
        self.keyLambdaWidget.setObjectName("keyLambdaWidget")
        self.verticalLayout_4 = QtWidgets.QVBoxLayout(self.keyLambdaWidget)
        self.verticalLayout_4.setObjectName("verticalLayout_4")
        self.cbx_LinesKey = QtWidgets.QComboBox(self.keyLambdaWidget)
        self.cbx_LinesKey.setEditable(True)
        self.cbx_LinesKey.setObjectName("cbx_LinesKey")
        self.verticalLayout_4.addWidget(self.cbx_LinesKey)
        self.label = QtWidgets.QLabel(self.keyLambdaWidget)
        self.label.setObjectName("label")
        self.verticalLayout_4.addWidget(self.label)
        self.edit_LinesKeyLambda = QtWidgets.QTextEdit(self.keyLambdaWidget)
        self.edit_LinesKeyLambda.setMaximumSize(QtCore.QSize(16777215, 80))
        self.edit_LinesKeyLambda.setTabStopWidth(16)
        self.edit_LinesKeyLambda.setObjectName("edit_LinesKeyLambda")
        self.verticalLayout_4.addWidget(self.edit_LinesKeyLambda)
        self.label_2 = QtWidgets.QLabel(self.keyLambdaWidget)
        self.label_2.setObjectName("label_2")
        self.verticalLayout_4.addWidget(self.label_2)
        self.formLayout_2.setWidget(1, QtWidgets.QFormLayout.FieldRole, self.keyLambdaWidget)
        self.lineWidth = QtWidgets.QLabel(self.groupBox_2)
        self.lineWidth.setObjectName("lineWidth")
        self.formLayout_2.setWidget(2, QtWidgets.QFormLayout.LabelRole, self.lineWidth)
        self.spin_lineWidth = QtWidgets.QDoubleSpinBox(self.groupBox_2)
        self.spin_lineWidth.setObjectName("spin_lineWidth")
        self.formLayout_2.setWidget(2, QtWidgets.QFormLayout.FieldRole, self.spin_lineWidth)
        self.lineColorWidget = QtWidgets.QWidget(self.groupBox_2)
        self.lineColorWidget.setObjectName("lineColorWidget")
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout(self.lineColorWidget)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        self.lineColorLabel = QtWidgets.QLabel(self.lineColorWidget)
        self.lineColorLabel.setObjectName("lineColorLabel")
        self.horizontalLayout_3.addWidget(self.lineColorLabel)
        self.edit_lineColor = QtWidgets.QLineEdit(self.lineColorWidget)
        self.edit_lineColor.setObjectName("edit_lineColor")
        self.horizontalLayout_3.addWidget(self.edit_lineColor)
        self.btn_lineColor = QtWidgets.QPushButton(self.lineColorWidget)
        self.btn_lineColor.setFlat(False)
        self.btn_lineColor.setObjectName("btn_lineColor")
        self.horizontalLayout_3.addWidget(self.btn_lineColor)
        self.formLayout_2.setWidget(3, QtWidgets.QFormLayout.SpanningRole, self.lineColorWidget)
        self.KeyLabel = QtWidgets.QLabel(self.groupBox_2)
        self.KeyLabel.setObjectName("KeyLabel")
        self.formLayout_2.setWidget(1, QtWidgets.QFormLayout.LabelRole, self.KeyLabel)
        self.verticalLayout_3.addLayout(self.formLayout_2)
        self.verticalLayout_5.addWidget(self.groupBox_2)
        spacerItem = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.verticalLayout_5.addItem(spacerItem)
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.verticalLayout.addWidget(self.scrollArea)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.btnAccept = QtWidgets.QPushButton(LinesDataConfig)
        self.btnAccept.setObjectName("btnAccept")
        self.horizontalLayout.addWidget(self.btnAccept)
        self.btnDiscard = QtWidgets.QPushButton(LinesDataConfig)
        self.btnDiscard.setObjectName("btnDiscard")
        self.horizontalLayout.addWidget(self.btnDiscard)
        self.verticalLayout.addLayout(self.horizontalLayout)

        self.retranslateUi(LinesDataConfig)
        QtCore.QMetaObject.connectSlotsByName(LinesDataConfig)
        LinesDataConfig.setTabOrder(self.nameLineEdit, self.spin_center_x)
        LinesDataConfig.setTabOrder(self.spin_center_x, self.spin_center_y)
        LinesDataConfig.setTabOrder(self.spin_center_y, self.enabledCheckBox)
        LinesDataConfig.setTabOrder(self.enabledCheckBox, self.edit_LinesKeyLambda)
        LinesDataConfig.setTabOrder(self.edit_LinesKeyLambda, self.spin_lineWidth)
        LinesDataConfig.setTabOrder(self.spin_lineWidth, self.btnAccept)
        LinesDataConfig.setTabOrder(self.btnAccept, self.btnDiscard)
        LinesDataConfig.setTabOrder(self.btnDiscard, self.scrollArea)

    def retranslateUi(self, LinesDataConfig):
        _translate = QtCore.QCoreApplication.translate
        LinesDataConfig.setWindowTitle(_translate("LineDataConfig", "Form"))
        self.groupBox.setTitle(_translate("LineDataConfig", "General:"))
        self.centerLabel.setText(_translate("LineDataConfig", "Center"))
        self.label_center_x.setText(_translate("LineDataConfig", "X:"))
        self.label_center_y.setText(_translate("LineDataConfig", "Y:"))
        self.enabledLabel.setText(_translate("LineDataConfig", "Enabled:"))
        self.nameLabel.setText(_translate("LineDataConfig", "Name:"))
        self.translationLabel.setText(_translate("LineDataConfig", "TransformationKey:"))
        self.label_4.setText(_translate("LineDataConfig", "def parse(input):"))
        self.label_3.setText(_translate("LineDataConfig", "return output"))
        self.groupBox_2.setTitle(_translate("LineDataConfig", "Lines:"))
        self.label.setText(_translate("LineDataConfig", "def parse(input):"))
        self.label_2.setText(_translate("LineDataConfig", "return output"))
        self.lineWidth.setText(_translate("LineDataConfig", "lineWidth:"))
        self.lineColorLabel.setText(_translate("LineDataConfig", "Color:"))
        self.btn_lineColor.setText(_translate("LineDataConfig", "Pick"))
        self.KeyLabel.setText(_translate("LineDataConfig", "Key:"))
        self.btnAccept.setText(_translate("LineDataConfig", "Accept"))
        self.btnDiscard.setText(_translate("LineDataConfig", "Discard"))

