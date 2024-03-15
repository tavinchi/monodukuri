function test() {
  var sheet = SpreadsheetApp.getActiveSpreadsheet().getActiveSheet();
  var cell1=sheet.getRange('A1');
  var cell2=sheet.getRange('B1');
  var cell3=sheet.getRange('C1');
  
  //テキストの文字を"開始"
  cell1.setValue("開始");
  //テキストを中央配置
  cell1.setHorizontalAlignment("center");
  //テキストを太字
  cell1.setFontWeight("bold");
  //テキストの背景色を薄い赤色
  cell1.setBackground("#ffe6e6");

  //テキストの文字を"終了"
  cell2.setValue("終了");
  //テキストを中央配置
  cell2.setHorizontalAlignment("center");
  //テキストを太字
  cell2.setFontWeight("bold");
  //テキストの背景色を薄い青色
  cell2.setBackground("#cce6ff");

  //テキストの文字を"回数"
  cell3.setValue("回数");
  //テキストを中央配置
  cell3.setHorizontalAlignment("center");
  //テキストを太字
  cell3.setFontWeight("bold");
  //テキストの背景色を薄い緑色
  cell3.setBackground("#e6ffcc");

}

function doGet(e) {
  var sheet = SpreadsheetApp.getActiveSpreadsheet().getActiveSheet();
  var data = e.parameter.count;
  var D_time=new Date();

  // 空いている最終行の取得
  var lastRow = sheet.getLastRow();

  // 空いているセルにデータを書き込む
  if(e.parameter.SE=="start"){
    sheet.getRange(lastRow+1,1).setValue(D_time);
  }else if(e.parameter.SE="end"){
    sheet.getRange(lastRow,2).setValue(D_time);
    sheet.getRange(lastRow,3).setValue(data);
  }
  
  return ContentService.createTextOutput('success');
}
