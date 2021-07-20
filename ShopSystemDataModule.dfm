object DModule: TDModule
  OldCreateOrder = False
  Height = 625
  Width = 863
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=Microsoft.ACE.OLEDB.12.0;Data Source=C:\Users\Programme' +
      'r\Shiko\Shiko Files\Career\TUT\2020 Sem 1\Shop Management Projec' +
      't\ShopDatabase.accdb;Persist Security Info=False'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.ACE.OLEDB.12.0'
    Left = 248
    Top = 48
  end
  object TCustomer: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Customer'
    Left = 72
    Top = 128
  end
  object DCustomer: TDataSource
    DataSet = TCustomer
    Left = 72
    Top = 176
  end
  object TFood: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'TFood'
    Left = 128
    Top = 128
  end
  object DSFood: TDataSource
    DataSet = TFood
    Left = 128
    Top = 176
  end
  object TFoodType: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'TFoodType'
    Left = 184
    Top = 128
  end
  object TFoodGroup: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'TFoodGroup'
    Left = 248
    Top = 128
  end
  object DSFoodType: TDataSource
    DataSet = TFoodType
    Left = 184
    Top = 176
  end
  object DSFoodGroup: TDataSource
    DataSet = TFoodGroup
    Left = 248
    Top = 176
  end
  object QueryFood: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    DataSource = DSFood
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM TFoodGroup;')
    Left = 312
    Top = 128
  end
  object QFoodDataAccess: TDataSource
    DataSet = QueryFood
    Left = 312
    Top = 176
  end
  object QueryFood2: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM Items;')
    Left = 392
    Top = 128
  end
  object TItems: TADOTable
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    TableName = 'Items'
    Left = 72
    Top = 232
  end
  object DSItems: TDataSource
    DataSet = TItems
    Left = 72
    Top = 288
  end
  object DataSource1: TDataSource
    DataSet = QueryFood2
    Left = 392
    Top = 176
  end
  object QuerySearchItems: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM Items;')
    Left = 480
    Top = 120
  end
  object DSSearchItems: TDataSource
    DataSet = QuerySearchItems
    Left = 480
    Top = 176
  end
  object ItemsList: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT productName, productPrice, FoodName FROM Items;')
    Left = 576
    Top = 120
  end
  object DSItemsList: TDataSource
    DataSet = ItemsList
    Left = 576
    Top = 176
  end
  object GeneralQuery: TADOQuery
    Active = True
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT productName, productPrice, FoodName FROM Items;')
    Left = 624
    Top = 120
  end
  object GeneralDS: TDataSource
    DataSet = GeneralQuery
    Left = 624
    Top = 176
  end
  object ADODataSet1: TADODataSet
    Parameters = <>
    Left = 696
    Top = 120
  end
  object DataSource2: TDataSource
    Left = 696
    Top = 176
  end
end
