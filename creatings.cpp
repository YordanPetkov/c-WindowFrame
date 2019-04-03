case WM_CREATE:    //TEXT BOX
{
CreateWindow)
TEXT("STATIC"),//TYPE window
TEXT("value"),//the text in box
WS_VISIBLE | WS_CHILD,//type box
10,//x
10,//y
100,//weight
25,//heigh
hwnd,//name of window 
(HMENU) NULL,//name of box
NULL,
NULL,
);
break
}

///--------------------------------------------------------------------------
case WM_CREATE : //BUTTON
{
   CreateWindow(
                TEXT("BUTTON"), //type WINDOW
                TEXT("button"), //text in box
                WS_VISIBLE | WS_CHILD,
                10,//x
                10,//y
                80,//weight
                20,//heigh
                hwnd, //parent of window (where it is)
                (HMENU) NULL , //name of window
                NULL,
                NULL
                ); 
                break;
}
///--------------------------------------------------------------------------
case WM_CREATE ://make a text box
{
    CreateWindow(
                 TEXT("EDIT"),//TEXT BOX
                 TEXT("VALUE"),
                 WS_VISIBLE | WS_CHILD | WS_BORDER,
                 10,10,200,25,
                 hwnd,(HMENU) NULL,NULL,NULL
                 );
                 
                 
}

///--------------------------------------------------------------------------
case WM_CREATE ://make a menu
{
    HMENU hMenubar = CreateMenu();//name of menu
    HMENU hFile = CreateMenu();
    HMENU hOptions = CreateMenu();
    
    AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hFile  , "File");//value of menu
    AppendMenu(hMenubar, MF_POPUP, NULL , "Edit");
    AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hOptions , "Options");
    
    AppendMenu(hFile, MF_STRING, NULL , "Exit");//Secondary menu
     AppendMenu(hOption, MF_STRING, NULL , "Option1");
      AppendMenu(hOption, MF_STRING, NULL , "Option 2");
    
    SetMenu(hwnd, hMenubar);//make a menu
    
    break;
}

///--------------------------------------------------------------------------
#define ID_BUTTON 1
LRESULT .....

case WM_CREATE :
{
    CreateWindow(TEXT("BUTTON"),TEXT("button"),
                 WS_CHILD | WS_VISIBLE,
                 10,10,80,20,
                 hwnd, (HMENU) ID_BUTTON, NULL ,NULL);
                 
    
    break;
}
case WM_COMMAND:
{
    if(LOWORD(wParam) == ID_BUTTON)//if button is pressed
    {
        MessageBox(hwnd, "button has been clicked", "title for popum", MB_ICONINFORMATION);
        //PostQuitMessage (0); // close the window
    }
    
    break;

}

///--------------------------------------------------------------------------



/* 33 */ wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND; -> wincl.hbrBackground =GetSysColorBrush(COLOR_3DFACE);//change color

/* 44 */ WS_OVERLAPPEDWINDOW, -> WS_SYSMENU // only with X

#define ID_BTN 1
#define ID_TEXTBOX 2

static HWND hwndTextbox; //make a hwnd window
case WM_CREATE:{
    hwndTextbox = CreateWindow(TEXT("EDIT"),TEXT("value"),
                 WS_VISIBLE | WS_CHILD | WS_BORDER | ES_AUTOHSCROLL , //ES_AUTOHSCROLL -> u can write always
                 10,10,200,20,
                 hwnd, (HMENU) ID_TEXTBOX, NULL ,NULL);
                 
    CreateWindow(TEXT("button"),TEXT("Click Me"),
                 WS_VISIBLE | WS_CHILD,
                 10,40,80,20,
                 hwnd, (HMENU) ID_BTN, NULL ,NULL)
    break;

}

case WM_COMMAND:{
    //action for default button
    if(LOWORD(wParam)== ID_BTN){
        // create some default vars
        int len = GetWindowTextLength(hwndTextbox)+1;
        static char* title[500];
        GetWindowText(hwndTextBox, title ,len);
        
        SetWindowText(hwnd, title);//set a title from edit box to window
        
        //MessageBox(hwnd, title ,"Message box", MB_OK);
    }
    break;
}



///-----------------------------------
case WM_PAINT :{
    hdc=BeginPaint(hWnd, &ps);
    
    //DRAWIND CODE :
    HPEN hPenOld;
    
    //Draw a red line
    HPEN hLinePen;
    COLORREF qLineColor;
    qLineColor = RGB(255,0,0);//COLOR of Line
    hLinePen = CreatePen(PS_SOLID,7,qLineColor);//type,width,color
    hPenOld = (HPEN) SelectObject(hdc,hLinePen);
    
    MoveToEx(hdc,100,100,NULL);
    LineTo(hdc,500,250);
    
    SelectObject(hdc,hPenOld);
    DeleteObject(hLinePen);
    
    //Draw a blue ellipse
    HPEN hEllipsePen;
    COLORREF qEllipseColor;
    qEllipseColor = RGB(0,0,255);
    hEllipsePen= CreatePen(PS_SOLID, 3 ,qEllipseColor);
    hPenOld = (HPEN) SelectObject(hdc,hEllipse);
    
    Arc(hdc,100,100,500,250,0,0,0,0);
    
    SelectObject(hdc,hPenOld);
    DeleteObject(hEllipsePen);
    
    EndPaint(hWnd,&ps);
    break;
}
