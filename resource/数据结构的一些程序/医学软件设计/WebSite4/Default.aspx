<%@ Page Language="C#" AutoEventWireup="true"  CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>无标题页</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
    </div>
    <asp:GridView ID="GridView1" runat="server" DataKeyNames="编号" 
        onrowdeleting="GridView1_RowDeleting" 
        onselectedindexchanging="GridView1_SelectedIndexChanging">
        <Columns>
            <asp:CommandField ShowSelectButton="True" />
            <asp:CommandField ShowDeleteButton="True" />
        </Columns>
    </asp:GridView>
    <p>
        编号：<asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        姓名：<asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
        性别：<asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
    </p>
    <p>
        地址：<asp:TextBox ID="TextBox4" runat="server"></asp:TextBox>
        电话：<asp:TextBox ID="TextBox5" runat="server"></asp:TextBox>
        生日：<asp:TextBox ID="TextBox6" runat="server"></asp:TextBox>
    </p>
    <p>
        <asp:Button ID="Button1" runat="server" Text="添加" Width="56px" 
            onclick="Button1_Click" />
        <asp:Button ID="Button2" runat="server" onclick="Button2_Click" Text="查询" 
            Width="49px" />
    </p>
    </form>
</body>
</html>
