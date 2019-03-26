<%@ Page Language="C#" AutoEventWireup="true" CodeFile="add.aspx.cs" Inherits="add" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        #Radio1 {
            width: 31px;
        }
    </style>
</head>
<body style="width: 286px; height: 160px">
    <form id="form1" runat="server">
    <div>
        <table style="height: 157px; width: 289px">
            <tr>
                <td><asp:Label ID="label1" runat="server" Text="Number1"></asp:Label></td>
                <td><asp:TextBox ID="tb1" runat="server"></asp:TextBox></td>
            </tr>
            <tr>
                <td><asp:Label ID="label2" runat="server" Text="Number2"></asp:Label></td>
                <td><asp:TextBox ID="tb2" runat="server" Height="22px"></asp:TextBox></td>
            </tr>
            <tr>
                <td colspan="2">
                    <asp:Button id="addBtn" runat="server" Text="Add" OnClick="addBtn_Click"/>
                </td>
            </tr>
            <tr>
                <td colspan="2">
                    <asp:Label ID="res" runat="server" Text="Result: "></asp:Label>
                </td>
            </tr>
        </table>
    </div>
    </form>
</body>
</html>
