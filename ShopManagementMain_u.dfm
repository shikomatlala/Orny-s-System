object shopName: TshopName
  Left = 0
  Top = 0
  Caption = 'Shiko'#39's Items'
  ClientHeight = 753
  ClientWidth = 1251
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 584
    Top = 344
    Width = 105
    Height = 105
  end
  object pcntrlMenuBar: TPageControl
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 1245
    Height = 747
    ActivePage = tbsIPurchase
    Align = alClient
    TabOrder = 0
    object tbsIPurchase: TTabSheet
      Caption = 'Purchase'
      ImageIndex = 3
      object pnlDecoPurchaseColor: TPanel
        Left = 0
        Top = 0
        Width = 1237
        Height = 719
        Align = alClient
        Caption = 'pnlDecoPurchaseColor'
        Color = clActiveCaption
        ParentBackground = False
        TabOrder = 0
        object PageControl1: TPageControl
          AlignWithMargins = True
          Left = 4
          Top = 4
          Width = 1229
          Height = 711
          ActivePage = tbsItemsCart
          Align = alClient
          TabOrder = 0
          object tbsItemsCart: TTabSheet
            Caption = 'Select Products'
            OnShow = tbsItemsCartShow
            object StringGrid1: TStringGrid
              Left = 431
              Top = 176
              Width = 787
              Height = 355
              Color = clWhite
              DefaultColWidth = 60
              DefaultRowHeight = 20
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              TabOrder = 0
              OnClick = StringGrid1Click
            end
            object pnlItmSlctOnLstDtls: TPanel
              Left = 429
              Top = 536
              Width = 723
              Height = 98
              TabOrder = 1
              object Panel3: TPanel
                Left = 1
                Top = 1
                Width = 721
                Height = 53
                Align = alClient
                Color = clMoneyGreen
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -27
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 0
              end
              object Panel5: TPanel
                Left = 1
                Top = 54
                Width = 721
                Height = 43
                Align = alBottom
                Color = clMoneyGreen
                Font.Charset = DEFAULT_CHARSET
                Font.Color = clWindowText
                Font.Height = -29
                Font.Name = 'Tahoma'
                Font.Style = [fsBold]
                ParentBackground = False
                ParentFont = False
                TabOrder = 1
              end
            end
            object Panel7: TPanel
              Left = 1145
              Top = 584
              Width = 74
              Height = 50
              Cursor = crHandPoint
              Caption = 'DOWN'
              Color = clSkyBlue
              ParentBackground = False
              TabOrder = 2
              OnClick = Panel7Click
            end
            object pnlCheckOut: TPanel
              Left = 733
              Top = 73
              Width = 100
              Height = 97
              Cursor = crHandPoint
              Caption = 'CHECKOUT'
              Color = clGreen
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -16
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 3
              OnClick = pnlCheckOutClick
            end
            object edtCIDEntry: TEdit
              Left = 903
              Top = 137
              Width = 249
              Height = 33
              Alignment = taCenter
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -21
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentFont = False
              TabOrder = 4
              TextHint = 'CID'
            end
            object pnlDltItmFrmList: TPanel
              Left = 427
              Top = 640
              Width = 796
              Height = 43
              Cursor = crHandPoint
              BorderStyle = bsSingle
              Caption = 'Delete Item'
              Color = clRed
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -21
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 5
              OnClick = pnlDltItmFrmListClick
            end
            object pnlItemPriceSum: TPanel
              Left = 1007
              Top = 73
              Width = 145
              Height = 58
              Caption = 'Price'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -21
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentFont = False
              TabOrder = 6
            end
            object pnlItmListCount: TPanel
              Left = 903
              Top = 73
              Width = 98
              Height = 59
              Caption = 'ITEMS'
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -16
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentFont = False
              TabOrder = 7
            end
            object pnlCIDEnter: TPanel
              Left = 839
              Top = 73
              Width = 58
              Height = 97
              Cursor = crHandPoint
              Caption = 'Enter'
              Color = clSkyBlue
              ParentBackground = False
              TabOrder = 8
              OnClick = pnlCIDEnterClick
            end
            object pnlAddItemsToCart: TPanel
              Left = 428
              Top = 73
              Width = 94
              Height = 97
              Cursor = crHandPoint
              Caption = 'ADD'
              Color = clYellow
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -37
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 9
              OnClick = pnlAddItemsToCartClick
              OnDblClick = pnlAddItemsToCartDblClick
            end
            object dbgItems2Select: TDBGrid
              Left = 2
              Top = 128
              Width = 420
              Height = 555
              DataSource = DModule.DSItemsList
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -12
              Font.Name = 'Tahoma'
              Font.Style = []
              ParentFont = False
              ReadOnly = True
              TabOrder = 10
              TitleFont.Charset = DEFAULT_CHARSET
              TitleFont.Color = clWindowText
              TitleFont.Height = -11
              TitleFont.Name = 'Tahoma'
              TitleFont.Style = []
              OnCellClick = dbgItems2SelectCellClick
              OnDblClick = dbgItems2SelectDblClick
              OnKeyDown = dbgItems2SelectKeyDown
              OnKeyUp = dbgItems2SelectKeyUp
            end
            object pnlAllItemsShow: TPanel
              Left = 3
              Top = 4
              Width = 134
              Height = 48
              Cursor = crHandPoint
              Caption = 'ALL ITEMS'
              Color = clGradientInactiveCaption
              ParentBackground = False
              TabOrder = 11
              OnClick = pnlAllItemsShowClick
            end
            object pnlNvgItemListCategory: TPanel
              Left = 72
              Top = 57
              Width = 289
              Height = 31
              Caption = 'ALL CATEGORIES'
              Color = clCream
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -21
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 12
            end
            object Panel4: TPanel
              Left = 1158
              Top = 0
              Width = 62
              Height = 131
              Cursor = crHandPoint
              Caption = 'Register'
              Color = clSkyBlue
              ParentBackground = False
              TabOrder = 13
              OnClick = Panel4Click
            end
            object Panel8: TPanel
              Left = 1158
              Top = 133
              Width = 62
              Height = 37
              Cursor = crHandPoint
              Caption = 'NONE'
              Color = clPurple
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWhite
              Font.Height = -11
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 14
              OnClick = Panel8Click
            end
            object Panel6: TPanel
              Left = 1145
              Top = 537
              Width = 74
              Height = 53
              Cursor = crHandPoint
              Caption = 'UP'
              Color = clSkyBlue
              ParentBackground = False
              TabOrder = 15
              OnClick = Panel6Click
            end
            object pnlSlctdItemPriceOnItems: TPanel
              Left = 528
              Top = 73
              Width = 199
              Height = 97
              Caption = 'PRICE'
              Color = clCream
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -24
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 16
            end
            object pnlSlctdItemNameOnItems: TPanel
              Left = 429
              Top = 3
              Width = 723
              Height = 64
              Caption = 'ITEM'
              Color = clCream
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clBlack
              Font.Height = -29
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 17
            end
            object ListBox1: TListBox
              Left = 438
              Top = 432
              Width = 145
              Height = 89
              ItemHeight = 13
              TabOrder = 18
              Visible = False
            end
            object ButtonGroup1: TButtonGroup
              Left = 0
              Top = 128
              Width = 422
              Height = 552
              Cursor = crHandPoint
              ButtonHeight = 70
              ButtonWidth = 65
              ButtonOptions = [gboAllowReorder, gboShowCaptions]
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Tahoma'
              Font.Style = []
              Items = <
                item
                  Caption = 'Milk'
                  OnClick = ButtonGroup1Items0Click
                end
                item
                  Caption = 'Protein Food'
                  OnClick = ButtonGroup1Items1Click
                end
                item
                  Caption = 'Mixed Dishes'
                  OnClick = ButtonGroup1Items2Click
                end
                item
                  Caption = 'Grains'
                  OnClick = ButtonGroup1Items3Click
                end
                item
                  Caption = 'Snacks & Sweets'
                  OnClick = ButtonGroup1Items4Click
                end
                item
                  Caption = 'Fruits'
                  OnClick = ButtonGroup1Items5Click
                end
                item
                  Caption = 'Vegetables'
                  OnClick = ButtonGroup1Items6Click
                end
                item
                  Caption = 'Non Alchoholic'
                  OnClick = ButtonGroup1Items7Click
                end
                item
                  Caption = 'Alcholohic'
                  OnClick = ButtonGroup1Items8Click
                end
                item
                  Caption = 'Water'
                  OnClick = ButtonGroup1Items9Click
                end
                item
                  Caption = 'Fish & Oils'
                  OnClick = ButtonGroup1Items10Click
                end
                item
                  Caption = 'Condiments & Sauces'
                  OnClick = ButtonGroup1Items11Click
                end
                item
                  Caption = 'Sugars'
                  OnClick = ButtonGroup1Items12Click
                end
                item
                  Caption = 'Infant Foods'
                  OnClick = ButtonGroup1Items13Click
                end
                item
                  Caption = 'Other'
                  OnClick = ButtonGroup1Items14Click
                end>
              TabOrder = 19
            end
            object pnlPicture: TPanel
              Left = 3
              Top = 344
              Width = 419
              Height = 336
              Caption = 'pnlPicture'
              TabOrder = 20
              object imgCategory: TImage
                Left = 1
                Top = 1
                Width = 417
                Height = 334
                Align = alClient
                AutoSize = True
                ExplicitLeft = 57
                ExplicitTop = 65
                ExplicitHeight = 254
              end
            end
            object SearchBox1: TSearchBox
              Left = 311
              Top = 101
              Width = 111
              Height = 21
              Hint = 'Search Items list'
              Color = clGradientInactiveCaption
              TabOrder = 21
              TextHint = 'Search Items'
              OnChange = SearchBox1Change
            end
            object cmbSearchInclude: TComboBox
              Left = 214
              Top = 101
              Width = 91
              Height = 21
              Hint = 'Specify the search kind'
              Color = clGradientInactiveCaption
              TabOrder = 22
              TextHint = 'Includes'
              Items.Strings = (
                'General'
                'Whole words only')
            end
            object pnlCountItems: TPanel
              Left = 3
              Top = 58
              Width = 71
              Height = 30
              Caption = 'COUNT'
              Color = clWhite
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 23
            end
            object pnlNvgItemListRight: TPanel
              Left = 360
              Top = 57
              Width = 62
              Height = 31
              Cursor = crHandPoint
              Caption = 'SWITCH'
              Color = clSkyBlue
              Font.Charset = DEFAULT_CHARSET
              Font.Color = clWindowText
              Font.Height = -13
              Font.Name = 'Tahoma'
              Font.Style = [fsBold]
              ParentBackground = False
              ParentFont = False
              TabOrder = 24
              OnClick = pnlNvgItemListRightClick
              OnDblClick = pnlNvgItemListRightDblClick
            end
            object cmbSearchCriteria: TComboBox
              Left = 110
              Top = 101
              Width = 98
              Height = 21
              Hint = 'Search Criteria'
              Color = clGradientInactiveCaption
              TabOrder = 25
              TextHint = 'Search Criteria'
              Items.Strings = (
                'Items'
                'Food'
                'Food Group')
            end
            object cmbSortItems: TComboBox
              Left = 3
              Top = 101
              Width = 85
              Height = 21
              Color = clGradientInactiveCaption
              TabOrder = 26
              TextHint = 'Sort Items'
              OnChange = cmbSortItemsChange
              Items.Strings = (
                'Name'
                'Price'
                'Food Name')
            end
            object pnlItemCatTable: TPanel
              Left = 143
              Top = 3
              Width = 278
              Height = 49
              Cursor = crHandPoint
              Caption = 'ITEM CATEGORY'
              Color = clGradientInactiveCaption
              ParentBackground = False
              TabOrder = 27
              OnClick = pnlItemCatTableClick
            end
            object AscDesc: TUpDown
              Left = 87
              Top = 101
              Width = 17
              Height = 21
              TabOrder = 28
              OnChanging = AscDescChanging
              OnClick = AscDescClick
            end
          end
          object TabSheet2: TTabSheet
            Caption = 'Purchase'
            ImageIndex = 1
            object Panel10: TPanel
              Left = 0
              Top = 0
              Width = 1221
              Height = 683
              Align = alClient
              Caption = 'Panel10'
              TabOrder = 0
              object Image2: TImage
                Left = 1
                Top = 1
                Width = 1219
                Height = 681
                Align = alClient
                ExplicitLeft = 577
                ExplicitTop = 240
                ExplicitWidth = 105
                ExplicitHeight = 105
              end
            end
            object pnlDate: TPanel
              Left = 520
              Top = 0
              Width = 185
              Height = 41
              Caption = 'pnlDate'
              TabOrder = 1
            end
          end
        end
      end
    end
    object tbsCustomer: TTabSheet
      Caption = 'Customer'
      OnShow = tbsCustomerShow
      object lblCID: TLabel
        Left = 56
        Top = 163
        Width = 18
        Height = 13
        Caption = 'CID'
      end
      object lblName: TLabel
        Left = 56
        Top = 190
        Width = 27
        Height = 13
        Caption = 'Name'
      end
      object lblSurname: TLabel
        Left = 56
        Top = 217
        Width = 42
        Height = 13
        Caption = 'Surname'
      end
      object lblID: TLabel
        Left = 56
        Top = 244
        Width = 11
        Height = 13
        Caption = 'ID'
      end
      object lblGender: TLabel
        Left = 56
        Top = 271
        Width = 35
        Height = 13
        Caption = 'Gender'
      end
      object lblDOB: TLabel
        Left = 56
        Top = 303
        Width = 29
        Height = 13
        Caption = 'D.O.B'
      end
      object Bevel1: TBevel
        Left = 424
        Top = 158
        Width = 289
        Height = 227
        Shape = bsFrame
      end
      object lblRegReport: TLabel
        Left = 184
        Top = 344
        Width = 3
        Height = 13
      end
      object lblSubReport: TLabel
        Left = 512
        Top = 163
        Width = 3
        Height = 13
      end
      object lblInfoName: TLabel
        Left = 304
        Top = 190
        Width = 3
        Height = 13
      end
      object lblInfoSurn: TLabel
        Left = 304
        Top = 217
        Width = 3
        Height = 13
      end
      object lblInfoID: TLabel
        Left = 304
        Top = 244
        Width = 3
        Height = 13
      end
      object lblInfoGen: TLabel
        Left = 304
        Top = 271
        Width = 3
        Height = 13
      end
      object lblInfoDOB: TLabel
        Left = 304
        Top = 295
        Width = 3
        Height = 13
      end
      object Label1: TLabel
        Left = 120
        Top = 141
        Width = 155
        Height = 13
        Caption = 'Click Get ID to obtain Product ID'
      end
      object edtCID: TEdit
        Left = 120
        Top = 160
        Width = 178
        Height = 21
        Hint = 'Customer ID'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 0
        TextHint = 'Click Get CID'
      end
      object edtName: TEdit
        Left = 120
        Top = 187
        Width = 178
        Height = 21
        TabOrder = 1
        TextHint = 'Name'
        OnChange = edtNameChange
      end
      object edtSurn: TEdit
        Left = 120
        Top = 214
        Width = 178
        Height = 21
        TabOrder = 2
        TextHint = 'Surname'
        OnChange = edtSurnChange
      end
      object edtID: TEdit
        Left = 120
        Top = 241
        Width = 178
        Height = 21
        TabOrder = 3
        TextHint = 'ID Number'
        OnChange = edtIDChange
        OnExit = edtIDExit
      end
      object cmbGender: TComboBox
        Left = 120
        Top = 268
        Width = 178
        Height = 21
        TabOrder = 4
        TextHint = 'Gender'
        OnChange = cmbGenderChange
        Items.Strings = (
          'Male'
          'Female'
          'Other')
      end
      object dtpDOB: TDateTimePicker
        Left = 120
        Top = 295
        Width = 178
        Height = 21
        BevelOuter = bvRaised
        Date = 43990.000000000000000000
        Time = 0.821229861110623500
        ParentShowHint = False
        ShowHint = True
        TabOrder = 5
      end
      object btnGetCID: TButton
        Left = 304
        Top = 158
        Width = 50
        Height = 25
        Caption = 'Get CID'
        TabOrder = 6
        OnClick = btnGetCIDClick
      end
      object btnEnterRegistration: TButton
        Left = 56
        Top = 344
        Width = 105
        Height = 25
        Caption = 'Enter Registration'
        TabOrder = 7
        OnClick = btnEnterRegistrationClick
      end
      object btnSubmitRegistration: TButton
        Left = 439
        Top = 167
        Width = 57
        Height = 25
        Caption = 'Submit'
        Enabled = False
        TabOrder = 8
        OnClick = btnSubmitRegistrationClick
      end
      object mmCustDetails: TMemo
        Left = 439
        Top = 198
        Width = 257
        Height = 140
        ReadOnly = True
        TabOrder = 9
      end
      object btnRegCust: TButton
        Left = 439
        Top = 349
        Width = 111
        Height = 25
        Caption = 'Register Customer'
        Enabled = False
        TabOrder = 10
        OnClick = btnRegCustClick
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 1237
        Height = 41
        Align = alTop
        Caption = 'ADD CUSTOMER'
        Color = clGradientActiveCaption
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Arial Black'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        TabOrder = 11
      end
      object pnlAddCustFinishRegister: TPanel
        Left = 631
        Top = 344
        Width = 58
        Height = 30
        Cursor = crHandPoint
        Caption = 'Finish'
        Enabled = False
        ParentBackground = False
        TabOrder = 12
        OnClick = pnlAddCustFinishRegisterClick
      end
      object Panel9: TPanel
        Left = 7
        Top = 7
        Width = 33
        Height = 26
        Caption = 'Back'
        TabOrder = 13
        OnClick = Panel9Click
      end
    end
    object tbsProduct: TTabSheet
      Caption = 'Register Product'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ImageIndex = 1
      ParentFont = False
      OnShow = tbsProductShow
      object lblGetIDHelp: TLabel
        Left = 171
        Top = 55
        Width = 182
        Height = 16
        Caption = 'Click Get ID to obtain Product ID'
      end
      object lblRegProdID: TLabel
        Left = 39
        Top = 80
        Width = 59
        Height = 16
        Caption = 'Product ID'
      end
      object lblRegProdName: TLabel
        Left = 39
        Top = 111
        Width = 80
        Height = 16
        Caption = 'Product Name'
      end
      object lblProdPrice: TLabel
        Left = 39
        Top = 142
        Width = 75
        Height = 16
        Caption = 'Product Price'
      end
      object lblEntrRegWarning: TLabel
        Left = 216
        Top = 178
        Width = 4
        Height = 16
        Layout = tlBottom
      end
      object Bevel2: TBevel
        Left = 399
        Top = 373
        Width = 370
        Height = 219
        Shape = bsFrame
      end
      object lblWarningName: TLabel
        Left = 359
        Top = 107
        Width = 4
        Height = 16
      end
      object lblProdStockPrice: TLabel
        Left = 39
        Top = 173
        Width = 110
        Height = 16
        Caption = 'Product Stock Price'
      end
      object lblProdStockDate: TLabel
        Left = 39
        Top = 204
        Width = 108
        Height = 16
        Caption = 'Product Stock Date'
      end
      object lblProdReorderLevel: TLabel
        Left = 39
        Top = 235
        Width = 126
        Height = 16
        Caption = 'Product Reorder Level'
      end
      object lblProdExpiryDate: TLabel
        Left = 39
        Top = 266
        Width = 118
        Height = 16
        Caption = 'Product Expiary Date'
      end
      object lblFoodName: TLabel
        Left = 39
        Top = 433
        Width = 65
        Height = 16
        Caption = 'Food Name'
      end
      object lblFoodID: TLabel
        Left = 39
        Top = 464
        Width = 44
        Height = 16
        Caption = 'Food ID'
      end
      object lblSupplierCompanyName: TLabel
        Left = 39
        Top = 495
        Width = 90
        Height = 16
        Caption = 'Company Name'
      end
      object lblItemSupplierID: TLabel
        Left = 39
        Top = 526
        Width = 63
        Height = 16
        Caption = 'Supplier ID'
      end
      object lblSelectFoodType: TLabel
        Left = 66
        Top = 304
        Width = 99
        Height = 16
        Caption = 'Select Food Type'
      end
      object lblFoodType: TLabel
        Left = 233
        Top = 329
        Width = 28
        Height = 16
        Caption = 'Type'
      end
      object lblFoodGroup: TLabel
        Left = 233
        Top = 359
        Width = 34
        Height = 16
        Caption = 'Group'
      end
      object lblFood: TLabel
        Left = 233
        Top = 389
        Width = 28
        Height = 16
        Caption = 'Food'
      end
      object lblProdList: TLabel
        Left = 544
        Top = 85
        Width = 86
        Height = 16
        Caption = 'PRODUCT LIST'
      end
      object Bevel3: TBevel
        Left = 39
        Top = 293
        Width = 314
        Height = 131
        Shape = bsFrame
      end
      object Bevel4: TBevel
        Left = 376
        Top = 139
        Width = 4
        Height = 438
        Shape = bsLeftLine
      end
      object edtRegProdID: TEdit
        Left = 176
        Top = 77
        Width = 177
        Height = 24
        Hint = 'Product ID'
        ParentShowHint = False
        ReadOnly = True
        ShowHint = True
        TabOrder = 0
        TextHint = 'Product ID'
      end
      object edtProdName: TEdit
        Left = 176
        Top = 108
        Width = 177
        Height = 24
        Hint = 'Product Name'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        TextHint = 'Product Name'
        OnChange = edtProdNameChange
      end
      object edtProdPrice: TEdit
        Left = 176
        Top = 139
        Width = 177
        Height = 24
        Hint = 'Product Price'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        TextHint = 'Product Price'
        OnChange = edtProdPriceChange
      end
      object edtPStockPrice: TEdit
        Left = 176
        Top = 170
        Width = 177
        Height = 24
        Hint = 'Stock Price'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 3
        TextHint = 'Stock Price'
        OnChange = edtPStockPriceChange
      end
      object dtpPOrderDate: TDateTimePicker
        Left = 176
        Top = 201
        Width = 177
        Height = 24
        Hint = 'Product Order Date'
        Date = 44039.000000000000000000
        Time = 0.821544907405041200
        ParentShowHint = False
        ShowHint = True
        TabOrder = 4
        OnChange = dtpPOrderDateChange
      end
      object edtPReorderLevel: TEdit
        Left = 176
        Top = 232
        Width = 177
        Height = 24
        Hint = 'Reorder Level'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 5
        TextHint = 'Reorder Level'
        OnChange = edtPReorderLevelChange
      end
      object dtpPExpiaryDate: TDateTimePicker
        Left = 176
        Top = 263
        Width = 177
        Height = 24
        Hint = 'Expiary Date'
        Date = 44039.000000000000000000
        Time = 0.821624027776124400
        ParentShowHint = False
        ShowHint = True
        TabOrder = 6
        OnChange = dtpPExpiaryDateChange
      end
      object edtPFoodName: TEdit
        Left = 176
        Top = 430
        Width = 177
        Height = 24
        Hint = 'Food Name'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ReadOnly = True
        ShowHint = True
        TabOrder = 7
        TextHint = 'Food Name'
        OnChange = edtPFoodNameChange
      end
      object edtPFoodID: TEdit
        Left = 176
        Top = 461
        Width = 177
        Height = 24
        Hint = 'Food ID'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        ParentShowHint = False
        ReadOnly = True
        ShowHint = True
        TabOrder = 8
        TextHint = 'Food ID'
        OnChange = edtPFoodIDChange
      end
      object edtPSupplierName: TEdit
        Left = 176
        Top = 492
        Width = 177
        Height = 24
        Hint = 'Supplier Company Name'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 9
        TextHint = 'Supplier Company Name'
        OnChange = edtPSupplierNameChange
      end
      object edtPSupplierID: TEdit
        Left = 176
        Top = 523
        Width = 177
        Height = 24
        Hint = 'Supplier ID'
        ParentShowHint = False
        ShowHint = True
        TabOrder = 10
        TextHint = 'Supplier ID'
        OnChange = edtPSupplierIDChange
      end
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 1237
        Height = 41
        Align = alTop
        Caption = 'ADD / EDIT PRODUCT'
        Color = clGradientActiveCaption
        Font.Charset = ANSI_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Arial Black'
        Font.Style = [fsBold]
        ParentBackground = False
        ParentFont = False
        TabOrder = 11
      end
      object Memo1: TMemo
        Left = 416
        Top = 388
        Width = 338
        Height = 177
        Lines.Strings = (
          'Memo1')
        TabOrder = 12
      end
      object dbcmbFoodType: TDBComboBox
        Left = 66
        Top = 328
        Width = 161
        Height = 24
        DataField = 'foodType'
        DataSource = DModule.DSFoodType
        TabOrder = 13
        OnChange = dbcmbFoodTypeChange
      end
      object dbcmbFoodGroup: TDBComboBox
        Left = 66
        Top = 358
        Width = 161
        Height = 24
        DataField = 'FoodGroup'
        DataSource = DModule.DSFoodGroup
        TabOrder = 14
        OnChange = dbcmbFoodGroupChange
      end
      object dbcmbFood: TDBComboBox
        Left = 66
        Top = 388
        Width = 161
        Height = 24
        DataField = 'FoodName'
        DataSource = DModule.DSFood
        Items.Strings = (
          'FOOD')
        TabOrder = 15
        OnChange = dbcmbFoodChange
      end
      object btnEnterProdReg: TButton
        Left = 39
        Top = 576
        Width = 118
        Height = 25
        Caption = 'Enter Registration'
        TabOrder = 16
        OnClick = btnEnterProdRegClick
      end
      object btnPRegistration: TButton
        Left = 399
        Top = 342
        Width = 112
        Height = 25
        Caption = 'Register Product'
        Enabled = False
        TabOrder = 17
        OnClick = btnPRegistrationClick
      end
      object dblPItemList: TDBListBox
        Left = 399
        Top = 107
        Width = 370
        Height = 213
        DataField = 'productName'
        DataSource = DModule.DSItems
        TabOrder = 18
      end
      object edtRegisterProduct: TButton
        Left = 399
        Top = 598
        Width = 94
        Height = 25
        Caption = 'Add Product'
        Enabled = False
        TabOrder = 19
        OnClick = edtRegisterProductClick
      end
      object btnRefreshList: TButton
        Left = 744
        Top = 81
        Width = 25
        Height = 20
        TabOrder = 20
        OnClick = btnRefreshListClick
      end
      object btnGetProdID: TButton
        Left = 359
        Top = 76
        Width = 51
        Height = 25
        Caption = 'Get PID'
        TabOrder = 21
        OnClick = btnGetProdIDClick
      end
    end
    object Customer: TTabSheet
      Caption = 'Customer'
      ImageIndex = 2
      object dbCustGrid: TDBGrid
        AlignWithMargins = True
        Left = 3
        Top = 3
        Width = 1231
        Height = 713
        Align = alClient
        DataSource = DModule.DCustomer
        GradientStartColor = clBtnFace
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'Tahoma'
        TitleFont.Style = []
        Columns = <
          item
            Expanded = False
            FieldName = 'CID'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'custName'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'custSurn'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'custID'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'sex'
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'dob'
            Visible = True
          end>
      end
    end
  end
  object Timer1: TTimer
    Interval = 10
    OnTimer = Timer1Timer
    Left = 152
    Top = 632
  end
  object cmpUpdater: TTimer
    Interval = 1
    OnTimer = cmpUpdaterTimer
    Left = 88
    Top = 632
  end
  object timerProdReport: TTimer
    Left = 16
    Top = 632
  end
end
