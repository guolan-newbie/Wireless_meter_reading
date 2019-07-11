// WenduDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Wendu.h"
#include "WenduDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define NOPARITY 0 
#define ODDPARITY 1 
#define EVENPARITY 2 
#define ONESTOPBIT 0 
#define ONE5STOPBITS 1 
#define TWOSTOPBITS 2 
#define CBR_110  110 
#define CBR_300  300 
#define CBR_600  600 
#define CBR_1200  1200 
#define CBR_2400  2400 
#define CBR_4800  4800 
#define CBR_9600  9600 
#define CBR_14400 14400 
#define CBR_19200 19200 
#define CBR_38400 38400 
#define CBR_56000 56000 
#define CBR_57600 57600 
#define CBR_115200 115200 
#define CBR_128000 128000 
#define CBR_256000 256000
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About


class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
	// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA
	
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWenduDlg dialog

CWenduDlg::CWenduDlg(CWnd* pParent /*=NULL*/)
: CDialog(CWenduDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWenduDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWenduDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWenduDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWenduDlg, CDialog)
//{{AFX_MSG_MAP(CWenduDlg)
ON_WM_SYSCOMMAND()
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2_send, OnBUTTON2_send)
	ON_EN_CHANGE(IDC_EDIT3_ZhengZongLiang, OnChangeEDIT3ZhengZongLiang)
	ON_EN_CHANGE(IDC_EDIT4_FuZhongLiang, OnChangeEDIT4FuZhongLiang)
	ON_EN_CHANGE(IDC_EDIT5_ShunShi, OnChangeEDIT5ShunShi)
	ON_EN_CHANGE(IDC_EDIT6_Time, OnChangeEDIT6Time)
	ON_EN_CHANGE(IDC_EDIT3_ZhengZongLiang2, OnChangeEDIT3ZhengZongLiang2_Units)
	ON_EN_CHANGE(IDC_EDIT4_FuZhongLiang2, OnChangeEDIT4FuZhongLiang2_Units)
	ON_EN_CHANGE(IDC_EDIT5_ShunShi2, OnChangeEDIT5ShunShi2_Units)
	ON_EN_CHANGE(IDC_EDIT6_DianYa, OnChangeEDIT6_DianYa)
	ON_EN_CHANGE(IDC_EDIT3_receive, OnChangeEDIT3receive)
	ON_WM_CANCELMODE()
	ON_WM_CTLCOLOR()
	ON_WM_CAPTURECHANGED()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWenduDlg message handlers

//g-�����ʼ��
BOOL CWenduDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CWenduDlg::GetCom();
	//flag =true;
	// Add "About..." menu item to system menu.
	
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	
	CFont *f = new CFont;        //�༭�������С
		f->CreateFont(
			20,	// �߶�
			0,  // nWidth
			0,  // nEscapement
			0,  // nOrientation
			0,  // nWeight
			FALSE, // bItalic
			FALSE, // bUnderline
			0,  // cStrikeOut
			ANSI_CHARSET,   // nCharSet
			OUT_DEFAULT_PRECIS, // nOutPrecision
			CLIP_DEFAULT_PRECIS, // nClipPrecision
			DEFAULT_QUALITY,  // nQuality
			DEFAULT_PITCH | FF_SWISS, // nPitchAndFamily
			_T("΢���ź�"));    // lpszFac  ��������

		((CEdit*)GetDlgItem(IDC_EDIT3_ZhengZongLiang))->SetFont(f);    //������ʾ����
		((CEdit*)GetDlgItem(IDC_EDIT4_FuZhongLiang))->SetFont(f);
		((CEdit*)GetDlgItem(IDC_EDIT5_ShunShi))->SetFont(f);
		((CEdit*)GetDlgItem(IDC_EDIT6_DianYa))->SetFont(f);
		((CEdit*)GetDlgItem(IDC_EDIT6_Time))->SetFont(f);
		((CEdit*)GetDlgItem(IDC_EDIT2_Send))->SetFont(f);
		((CEdit*)GetDlgItem(IDC_EDIT3_receive))->SetFont(f);	
		//pDC->SetTextColor(RGB(255,0,0));					 //����������ɫ
		m_brush.CreateSolidBrush(RGB(255,0,0));				 //������ˢ
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWenduDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CWenduDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWenduDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//g-�򿪴��ں���
void CWenduDlg::GUO_OpenCK()
{
	//HANDLE hCom;//ȫ�ֱ���,���ھ�� 
	//hCom=CreateFile("\\\\.\\COM10",GENERIC_READ|GENERIC_WRITE,1,NULL,OPEN_EXISTING,0,NULL); //����������0��ռ��1�Ƕ�ռ
	hCom=CreateFile(selStr,GENERIC_READ|GENERIC_WRITE,1,NULL,OPEN_EXISTING,0,NULL); //����������0��ռ��1�Ƕ�ռ
	if(hCom==(HANDLE)-1) //�����ǿ������ת��
	{ 
		MessageBox("��COMʧ��!"); 
	} 
	else
	{
		//MessageBox("�����Ѵ�!"); 
		this->SetDlgItemText(IDOK,"�Ѵ�");
	}
	///////////////////////////////////////////////////////////////////
	SetupComm(hCom,1024,1024);//���뻺����������������Ĵ�С���� 1024 
	COMMTIMEOUTS TimeOuts; //�趨����ʱ 
	TimeOuts.ReadIntervalTimeout=1000; 
	TimeOuts.ReadTotalTimeoutMultiplier=500; 
	TimeOuts.ReadTotalTimeoutConstant=5000;		//�趨д��ʱ 
	TimeOuts.WriteTotalTimeoutMultiplier=500; 
	TimeOuts.WriteTotalTimeoutConstant=2000; 
	SetCommTimeouts(hCom,&TimeOuts);			//���ó�ʱ 
	DCB dcb; 
	GetCommState(hCom,&dcb); 
	dcb.BaudRate=2400;                   //g-������Ϊ2400 
	dcb.ByteSize=8;						 //g-ÿ���ֽ�8λ 
	//dcb.Parity=NOPARITY;               //����żУ��λ 
	dcb.Parity=EVENPARITY;               //g-żУ��λ
	//dcb.StopBits=TWOSTOPBITS;          //2��ֹͣλ 
	dcb.StopBits=ONE5STOPBITS;           //g-1��ֹͣλ
	SetCommState(hCom,&dcb); 
	PurgeComm(hCom,PURGE_TXCLEAR|PURGE_RXCLEAR);
}


//g-������Ӧ�¼�
void CWenduDlg::OnOK() 
{
	// TODO: Add extra validation here
	 
	GUO_OpenCK();  //ͬ��������
	(CButton *)GetDlgItem(IDOK)->EnableWindow(FALSE);   //g-����Ϊ���ɱ༭״̬
	/*
	SetTimer(1,500,NULL); //������ʱ��
	if(hCom==(HANDLE)-1)  //�������δ�����򿪣��ض�ʱ��
	{
		KillTimer(1);	  //�ض�ʱ��
	}*/
}


//g-UI��ɾ��
void CWenduDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CloseHandle(hCom);//�ش���
	KillTimer(1);//�ض�ʱ��
}


//g-��ʱ����Ӧ����
void CWenduDlg::OnTimer(UINT nIDEvent)              
{
	// TODO: Add your message handler code here and/or call default
	/*count++;*/
	
	if(1==nIDEvent)
	{
		CString arr[40];         //���ת�����ʮ������
	 	unsigned char str[40]; 
		DWORD rCount=40;         //��ȡ���ֽ��� 
		BOOL bReadStat;          //��ȡ״̬ 
		bReadStat=ReadFile(hCom,str,rCount,&rCount,NULL); 
		if(!bReadStat)
		{ 
			MessageBox("������ʧ��!"); 
			CloseHandle(hCom);   //�ش���
			KillTimer(1);        //�ض�ʱ��
			//return FALSE; 
		} 
		else
		{
			
			CString gg="";

			for(int i=0; i<40; i++)
			{	
				CString temp; 
					temp.Format( _T("%02x"),str[i]);       //ռ��λ����
					arr[i] = temp;
					if(i%10 == 0)    //����
					{	
						if(i!=0){
							gg=gg+ "\r\n";
						}
					}
				gg=gg+temp+" ";
			}
			
   
			this->SetDlgItemText(IDC_EDIT3_receive,gg); 
			KillTimer(1);//�ض�ʱ��


			CString temp2; 
			temp2.Format( _T("%x"),str[18]);

			CString DianYa; 
			DianYa.Format( _T("%d"),str[13]);
			double DianYa_i = _ttoi(DianYa);
			DianYa.Format(_T("%.2f"), (DianYa_i*2)/100);
			this->SetDlgItemText(IDC_EDIT6_DianYa,DianYa+"v");          //����ģ���ѹֵ


			CString ZhengZhongLiang = arr[17] + arr[16] + arr[15] + arr[14];
			CString FanZhongLiang   = arr[22] + arr[21] + arr[20] + arr[19];
			CString ShunShiLiang    = arr[27] + arr[26] + arr[25] + arr[24];
			CString ChaoBiaoTime    = arr[35] + arr[34] + "-" + arr[33] +"-"+ arr[32] + " " + arr[31] + ":" + arr[30]+ ":" + arr[29];
			
			
			
			CString Zheng_S = _T(ZhengZhongLiang);
			int Zheng_i = _ttoi(Zheng_S);
			ZhengZhongLiang.Format(_T("%d"), Zheng_i);

			CString Fan_S = _T(FanZhongLiang);
			int Fan_i = _ttoi(Fan_S);
			FanZhongLiang.Format(_T("%d"), Fan_i);

			CString Shun_S = _T(ShunShiLiang);
			int Shun_i = _ttoi(Shun_S);
			ShunShiLiang.Format(_T("%d"), Shun_i);

			if(strcmp(arr[18],"29")==0)                                //����������λ
				{this->SetDlgItemText(IDC_EDIT3_ZhengZongLiang2,"L");}
			if(strcmp(arr[18],"2A")==0)
				{this->SetDlgItemText(IDC_EDIT3_ZhengZongLiang2,"10L");}
			if(strcmp(arr[18],"2B")==0)
				{this->SetDlgItemText(IDC_EDIT3_ZhengZongLiang2,"100L");} 
			if(strcmp(arr[18],"2C")==0)
				{this->SetDlgItemText(IDC_EDIT3_ZhengZongLiang2,"1000L");}

			if(strcmp(arr[23],"29")==0)                               //����������λ
				{this->SetDlgItemText(IDC_EDIT4_FuZhongLiang2,"L");}
			if(strcmp(arr[23],"2A")==0)
				{this->SetDlgItemText(IDC_EDIT4_FuZhongLiang2,"10L");}
			if(strcmp(arr[23],"2B")==0)
				{this->SetDlgItemText(IDC_EDIT4_FuZhongLiang2,"100L");} 
			if(strcmp(arr[23],"2C")==0)
				{this->SetDlgItemText(IDC_EDIT4_FuZhongLiang2,"1000L");}

			if(strcmp(arr[28],"32")==0)                               //˲ʱ������λ
				{this->SetDlgItemText(IDC_EDIT5_ShunShi2,"L/h");}
			if(strcmp(arr[28],"33")==0)
				{this->SetDlgItemText(IDC_EDIT5_ShunShi2,"10L/h");}
			if(strcmp(arr[28],"34")==0)
				{this->SetDlgItemText(IDC_EDIT5_ShunShi2,"100L/h");} 


			this->SetDlgItemText(IDC_EDIT3_ZhengZongLiang,ZhengZhongLiang); 
			this->SetDlgItemText(IDC_EDIT4_FuZhongLiang,FanZhongLiang);
			this->SetDlgItemText(IDC_EDIT5_ShunShi,ShunShiLiang);
			this->SetDlgItemText(IDC_EDIT6_Time,ChaoBiaoTime);
			//this->SetDlgItemText(IDC_EDIT6_DianYa,DianYa);

			
			/*wendu = ((int)str[3])*10 + ((int)str[2]);*/
		} 
		
		PurgeComm(hCom,PURGE_TXABORT|PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR); 
		UpdateData(FALSE);
		
	}
	/////////////////////////////
	//CDialog::OnTimer(nIDEvent);
	/*
	if(count>10)
		 {
	  		count = 5;	  //��ֹcountԽ��
		 }
		if( ((wendu > 21) && (count > 3)) && flag==0 )
		{
			MessageBox("���ȣ�������!");
			count = 0;
			flag = 1;
		}*/
	
}

/*
void CWenduDlg::OnChangeEdit2_send() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}*/


//g-���ݷ��ͺ���
void CWenduDlg::OnBUTTON2_send() 
{
	// TODO: Add your control notification handler code here
	CString text;
	this->GetDlgItem(IDC_EDIT2_Send)->GetWindowText(text);  //�ı����ţ�54270982

	if(text.GetLength()!=8)
		{
		MessageBox("�������,���������ˣ�");
		//flag =false;
		}
	else{
		//char m_TXData[16]={0x68,0x10,0x54,0x27,0x09,0x82,0x00,0x11,0x11,0x01,0x03,0x90,0x1F,0x00,0x53,0x16};
		char m_TXData[16];
		 m_TXData[0] =0x68;       //��ʼ�� 
		 m_TXData[1] =0x10;
		 m_TXData[2] =strtol(text.Mid(0,2),NULL,16);          //���
		 m_TXData[3] =strtol(text.Mid(2,2),NULL,16);
		 m_TXData[4] =strtol(text.Mid(4,2),NULL,16);
		 m_TXData[5] =strtol(text.Mid(6,2),NULL,16);
		 m_TXData[6] =0x00;   
	     m_TXData[7] =0x11;
		 m_TXData[8] =0x11;
		 m_TXData[9] =0x01;
		 m_TXData[10] =0x03; 
		 m_TXData[11] =0x90; 
		 m_TXData[12] =0x1F;
		 m_TXData[13] =0x00;
	     m_TXData[14] =strtol(this->checksum(m_TXData),NULL,16);   //У���        
		 m_TXData[15] =0x16;       //������
	
	//MessageBox(this->checksum(m_TXData));
		 //CString guolilu;
		 //guolilu.Format(_T("%d"), strtol(text.Mid(0,2),NULL,10));
	//MessageBox(guolilu);
	//MessageBox(text.Mid(0,2));  //��ȡǰ��λ
	//MessageBox(text.Mid(2,2));  //��ȡǰ��λ
	//MessageBox(text.Mid(4,2));  //��ȡǰ��λ
	//MessageBox(text.Mid(6,2));  //��ȡǰ��λ
	
	DWORD wCount=16;//��ȡ���ֽ��� 
	BOOL bWriteStat;//��ȡ״̬ 
	bWriteStat=WriteFile(hCom,m_TXData,wCount,&wCount,NULL);      //��������
	SetTimer(1,1000,NULL); //������ʱ��
	}
}


//g-У��ͺ���
CString CWenduDlg::checksum(char *m_TXData)       
{
	int sum=0;
	CString sum_s;
	for(int i=0;i<14;i++)
	{
		sum = sum+m_TXData[i];
	}
	sum_s.Format(_T("%x"), sum);
	sum_s = sum_s.Mid(sum_s.GetLength()-2,2);     //ȡ����λ��ΪУ��ͣ�����61
	//MessageBox(sum_s);
	return sum_s;
}


//g-����������ɫ
HBRUSH CWenduDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)     
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	// TODO: Return a different brush if the default is not desired
	if((pWnd->GetDlgCtrlID() == IDC_EDIT6_DianYa))
	{
		pDC->SetTextColor(RGB(255,0,0));
	}
	if((pWnd->GetDlgCtrlID() == IDC_EDIT3_ZhengZongLiang))
	{
		pDC->SetTextColor(RGB(255,0,0));
	}
	if((pWnd->GetDlgCtrlID() == IDC_EDIT4_FuZhongLiang))
	{
		pDC->SetTextColor(RGB(255,0,0));
	}
	if((pWnd->GetDlgCtrlID() == IDC_EDIT5_ShunShi))
	{
		pDC->SetTextColor(RGB(255,0,0));
	}
	if((pWnd->GetDlgCtrlID() == IDC_EDIT6_Time))
	{
		pDC->SetTextColor(RGB(0,,0,255));
	}
	
	return hbr;
}


//g-�Զ�ʶ�𴮿�
void CWenduDlg::GetCom()
{	
 //HANDLE hCom;						//��������ʱ��ȡȫ�����ô���
 int i,num,k;
 CString str;
 BOOL flag;
 ((CComboBox *)GetDlgItem(IDC_COMBO1))->ResetContent();
 flag = FALSE;
 num = 0;
 for (i = 1;i<= 16;i++)
 {									//�˳���֧��16������
	str.Format("\\\\.\\COM%d",i);
	hCom = CreateFile(str, 0, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if(INVALID_HANDLE_VALUE != hCom )
	{									//�ܴ򿪸ô��ڣ�����Ӹô���
		CloseHandle(hCom);
		str = str.Mid(4);               //��4����β
		((CComboBox *)GetDlgItem(IDC_COMBO1))->AddString(str);
		if (flag == FALSE)
		{
			flag = TRUE;
			num = i;
		}
	}
 }

 i = ((CComboBox *)GetDlgItem(IDC_COMBO1))->GetCount();

 if (i == 0)
 {										//���Ҳ������ô�������á��򿪴��ڡ�����
	((CComboBox *)GetDlgItem(IDC_COMBO1))->EnableWindow(FALSE);
 }
 else
 {
	 	 k = ((CComboBox *)GetDlgItem((IDC_COMBO1)))->GetCount();
	 	 ((CComboBox *)GetDlgItem(IDC_COMBO1))->SetCurSel(k - 1);           //ͨ������indexָ��
	 	 //CString selStr;
	 	 //GetDlgItemText(IDC_COMBO1,selStr);                               //��ȡ�ı�
	 
	 	 int nIndex = ((CComboBox *)GetDlgItem(IDC_COMBO1))->GetCurSel();   //ȡ������
	 	 ((CComboBox *)GetDlgItem(IDC_COMBO1))->GetLBText(nIndex,selStr);
	 	//MessageBox(selStr);
	 	//mCom.BindCommPort(num);	 
}
}









/***********************************************************************************************
                                   ���´�������Թ�
************************************************************************************************/
void CWenduDlg::OnChangeEDIT3ZhengZongLiang() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CWenduDlg::OnChangeEDIT4FuZhongLiang() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CWenduDlg::OnChangeEDIT5ShunShi() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CWenduDlg::OnChangeEDIT6Time() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CWenduDlg::OnChangeEDIT3ZhengZongLiang2_Units() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CWenduDlg::OnChangeEDIT4FuZhongLiang2_Units() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CWenduDlg::OnChangeEDIT5ShunShi2_Units() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

void CWenduDlg::OnChangeEDIT6_DianYa() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}

//DEL void CWenduDlg::OnChangeEDIT2_Send() 
//DEL {
//DEL 	// TODO: If this is a RICHEDIT control, the control will not
//DEL 	// send this notification unless you override the CDialog::OnInitDialog()
//DEL 	// function and call CRichEditCtrl().SetEventMask()
//DEL 	// with the ENM_CHANGE flag ORed into the mask.
//DEL 	
//DEL 	// TODO: Add your control notification handler code here
//DEL 	
//DEL }


//DEL checksum CWenduDlg::CString()
//DEL {
//DEL 
//DEL }

void CWenduDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void CWenduDlg::OnChangeEDIT3receive() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
}

//DEL HBRUSH CWenduDlg::OnCtlColor(CDC *pDC, CWnd *pWnd, UINT nCtlColor)
//DEL {
//DEL HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
//DEL if(pWnd->GetDlgCtrlID()==IDC_EDIT6_DianYa)      
//DEL {
//DEL    pDC->SetTextColor(RGB(255,0,0));
//DEL    //pDC->SetBkColor(RGB(255,255,0));//�����ı�����ɫ
//DEL    //pDC->SetBkMode(TRANSPARENT);//���ñ���͸��
//DEL    return CreateSolidBrush(RGB(255,0,0));
//DEL }
//DEL return hbr;
//DEL }

//DEL HBRUSH CWenduDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
//DEL {
//DEL 	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
//DEL 	if(pWnd->GetDlgCtrlID()==IDC_EDIT6_DianYa)      
//DEL {
//DEL    pDC->SetTextColor(RGB(255,0,0));
//DEL    //pDC->SetBkColor(RGB(255,255,0));//�����ı�����ɫ
//DEL    //pDC->SetBkMode(TRANSPARENT);//���ñ���͸��
//DEL    return CreateSolidBrush(RGB(255,0,0));
//DEL }
//DEL 	
//DEL 	// TODO: Change any attributes of the DC here
//DEL 	
//DEL 	// TODO: Return a different brush if the default is not desired
//DEL 	return hbr;
//DEL }

void CWenduDlg::OnCancelMode() 
{
	CDialog::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CWenduDlg::OnCaptureChanged(CWnd *pWnd) 
{
	// TODO: Add your message handler code here
	
	CDialog::OnCaptureChanged(pWnd);
}

//DEL void CWenduDlg::GetCom()
//DEL {
//DEL 	 //��������ʱ��ȡȫ�����ô���
//DEL  HANDLE hCom;
//DEL  int i,num,k;
//DEL  CString str;
//DEL  BOOL flag;
//DEL  
//DEL  ((CComboBox *)GetDlgItem(IDC_COMBO1))->ResetContent();
//DEL  flag = FALSE;
//DEL  num = 0;
//DEL  for (i = 1;i <= 16;i++)
//DEL  {//�˳���֧��16������
//DEL  str.Format("\\\\.\\COM%d",i);
//DEL  hCom = CreateFile(str, 0, 0, 0, 
//DEL  OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
//DEL  if(INVALID_HANDLE_VALUE != hCom )
//DEL  {//�ܴ򿪸ô��ڣ�����Ӹô���
//DEL  CloseHandle(hCom);
//DEL  str = str.Mid(4);
//DEL  ((CComboBox *)GetDlgItem(IDC_COMBO1))->AddString(str);
//DEL  if (flag == FALSE)
//DEL  {
//DEL  flag = TRUE;
//DEL  num = i;
//DEL  }
//DEL  }
//DEL  }
//DEL  i = ((CComboBox *)GetDlgItem(IDC_COMBO1))->GetCount();
//DEL  if (i == 0)
//DEL  {//���Ҳ������ô�������á��򿪴��ڡ�����
//DEL  ((CComboBox *)GetDlgItem(IDC_COMBO1))->EnableWindow(FALSE);
//DEL  }
//DEL  else
//DEL  {
//DEL  k = ((CComboBox *)GetDlgItem((IDC_COMBO1)))->GetCount();
//DEL  ((CComboBox *)GetDlgItem(IDC_COMBO1))->SetCurSel(k - 1);
//DEL  //mCom.BindCommPort(num);
//DEL  }
//DEL }
