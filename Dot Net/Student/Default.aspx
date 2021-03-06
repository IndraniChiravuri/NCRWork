﻿<%@ Page Language="C#" AutoEventWireup="true" CodeFile="Default.aspx.cs" Inherits="_Default" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .auto-style1 {
            width: 189px;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    
        <table style="width:100%;">
            <tr>
                <td class="auto-style1">Name: </td>
                <td>
                    <asp:TextBox ID="name" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style1">Roll No: </td>
                <td>
                    <asp:TextBox ID="rollNo" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style1">Year: </td>
                <td>
                    <asp:TextBox ID="year" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td class="auto-style1">Branch: </td>
                <td>
                    <asp:TextBox ID="branch" runat="server"></asp:TextBox>
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Button ID="add" runat="server" Text="Add Student" OnClick="add_Click"/>
                </td>
                <td>
                    <asp:Button ID="show" runat="server" Text="Show Students" OnClick="show_Click"/>
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Button ID="update" runat="server" Text="Update" OnClick="update_Click" />
                </td>
                <td>
                    <asp:Button ID="delete" runat="server" Text="Delete Student" OnClick="delete_Click"/>
                </td>
            </tr>
            <tr colspan="2" align ="center">
                <td>
                    <asp:Button ID="reset" runat="server" Text="Reset" OnClick="reset_Click" />
                </td>
            </tr>
        </table>
        <asp:GridView ID="result" runat="server" BorderStyle="Double" AutoGenerateDeleteButton="true"></asp:GridView>
    </div>
    </form>
</body>
</html>
