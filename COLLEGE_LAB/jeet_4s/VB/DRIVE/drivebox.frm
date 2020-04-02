VERSION 5.00
Begin VB.Form Form1 
   BackColor       =   &H8000000B&
   Caption         =   "Form1"
   ClientHeight    =   5310
   ClientLeft      =   120
   ClientTop       =   450
   ClientWidth     =   9555
   LinkTopic       =   "Form1"
   ScaleHeight     =   5310
   ScaleWidth      =   9555
   StartUpPosition =   3  'Windows Default
   Begin VB.CommandButton Command1 
      Caption         =   "SHOW"
      BeginProperty Font 
         Name            =   "Palatino Linotype"
         Size            =   15.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   615
      Left            =   840
      TabIndex        =   4
      Top             =   4200
      Width           =   1575
   End
   Begin VB.TextBox Text1 
      Height          =   615
      Left            =   3720
      TabIndex        =   3
      Top             =   360
      Width           =   5055
   End
   Begin VB.FileListBox File1 
      Height          =   3405
      Left            =   3240
      TabIndex        =   2
      Top             =   1440
      Width           =   1815
   End
   Begin VB.DirListBox Dir1 
      Height          =   2565
      Left            =   480
      TabIndex        =   1
      Top             =   1320
      Width           =   2535
   End
   Begin VB.DriveListBox Drive1 
      Height          =   315
      Left            =   480
      TabIndex        =   0
      Top             =   480
      Width           =   2535
   End
   Begin VB.Image Image1 
      Height          =   3375
      Left            =   5640
      Stretch         =   -1  'True
      Top             =   1440
      Width           =   3615
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Dim f As String

Private Sub Command1_Click()
Image1.Picture = LoadPicture(f)
Text1.Text = f
End Sub

Private Sub Dir1_Change()
File1.Path = Dir1.Path
End Sub

Private Sub Drive1_Change()
Dir1.Path = Drive1.Drive
End Sub

Private Sub File1_Click()
f = File1.Path
If Right(f, 1) <> "/" Then
f = File1.Path + "/" + File1.FileName
End If

End Sub

Private Sub Form_Load()
Drive1.Drive = "c"
End Sub
