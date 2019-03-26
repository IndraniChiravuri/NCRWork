using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class add : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }
    protected void addBtn_Click(object sender, EventArgs e)
    {
        int n1 = int.Parse(tb1.Text);
        int n2 = int.Parse(tb2.Text);
        res.Text = sum(n1,n2).ToString();
    }

    private int sum(int n1, int n2)
    {
        return n1 + n2;
    }
}