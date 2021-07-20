object DMSelectProduct: TDMSelectProduct
  OldCreateOrder = False
  Height = 599
  Width = 849
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\Users\Programme' +
      'r\Shiko\Shiko Files\Career\TUT\2020 Sem 1\Shop Management Projec' +
      't\ShopDatabase.accdb;Persist Security Info=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.ACE.OLEDB.12.0'
    Left = 288
    Top = 48
  end
  object ItemsQueryDatasource: TDataSource
    DataSet = ADOItemsQuery
    Left = 120
    Top = 104
  end
  object ADOTable1: TADOTable
    Left = 528
    Top = 264
  end
  object ADOItemsQuery: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT productName, productPrice, FoodName FROM Items;')
    Left = 112
    Top = 48
  end
  object ADOItemsQueryExtractInfo: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    DataSource = ItemsQueryDatasource
    Parameters = <>
    SQL.Strings = (
      'SELECT productName, productPrice, FoodName FROM Items;')
    Left = 288
    Top = 96
  end
  object ItemsQueryDatasourceExtractInfo: TDataSource
    DataSet = ADOItemsQueryExtractInfo
    Left = 288
    Top = 152
  end
  object ADOItemTypeQuery: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM TFoodType;')
    Left = 600
    Top = 144
  end
  object ADOItemsTypeDS: TDataSource
    DataSet = ADOItemTypeQuery
    Left = 608
    Top = 200
  end
  object CountItemsQuery: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT COUNT(productID) AS ItemCount FROM Items;')
    Left = 144
    Top = 304
  end
  object CountItemsDataSource: TDataSource
    DataSet = CountItemsQuery
    Left = 144
    Top = 360
  end
end
