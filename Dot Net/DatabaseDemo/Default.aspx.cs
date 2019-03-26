using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void addBtn_Click(object sender, EventArgs e)
    {
        int n1 = int.Parse(Number1.Text);
        int n2 = int.Parse(Number2.Text);
        res.Text = (n1 + n2).ToString();
    }
}