<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 167px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table style="width:100%;">
        <tr>
            <td class="auto-style1">Number1</td>
            <td><asp:TextBox ID="Number1" runat="server"></asp:TextBox></td>
        </tr>
        <tr>
            <td class="auto-style1">Number2</td>
            <td><asp:TextBox ID="Number2" runat="server"></asp:TextBox></td>
        </tr>
        <tr colspan="2" align="center">
            <td class="auto-style1"><asp:Button ID="addBtn" runat="server" OnClick="addBtn_Click" Text="Add" Width="65px"></asp:Button></td>
        </tr>
        <tr>
            <td class="auto-style1">Result</td>
            <td><asp:TextBox ID="res" runat="server"></asp:TextBox></td>
        </tr>
    </table>
    </div>
    </form>
</body>
</html>
