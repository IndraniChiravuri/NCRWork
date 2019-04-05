using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data;
using System.Data.SqlClient;
using Class;

public partial class Update : System.Web.UI.Page
{
    
    protected void Page_Load(object sender, EventArgs e)
    {
        
        if (Page.IsPostBack == false)
        {
            DataSet ds = new DataSet();
            Class.Class1 obj = new Class.Class1();
            ds = obj.countryP();
            DropDownList1.DataTextField = ds.Tables[0].Columns["Country"].ToString();
            DropDownList1.DataSource = ds.Tables[0];
            DropDownList1.DataBind();
            

        }
        if (Page.IsPostBack == false)
        {
            DataSet ds = new DataSet();
            Class.Class1 obj = new Class.Class1();
            ds = obj.roleP();
            DropDownList3.DataTextField = ds.Tables[0].Columns["Role"].ToString();
            DropDownList3.DataSource = ds.Tables[0];
            DropDownList3.DataBind();


        }





    }



    protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
    {
        if (!Page.IsPostBack==false)
        {

            string coun = DropDownList1.SelectedItem.Text;
            DataSet ds = new DataSet();
            Class.Class1 obj = new Class.Class1();
            ds = obj.stateP(coun);

            DropDownList2.DataTextField = ds.Tables[0].Columns["State"].ToString();
            DropDownList2.DataSource = ds.Tables[0];
            DropDownList2.DataBind();

           

        }


    }

    protected void DropDownList2_SelectedIndexChanged(object sender, EventArgs e)
    {

    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        Objs objects = new Objs();
        objects.EmpId = int.Parse(TextBox1.Text);
        objects.Name = TextBox2.Text;
        objects.phone = TextBox3.Text;
        objects.email = TextBox4.Text;
        objects.date = Calendar1.SelectedDate.ToString();
        objects.country = DropDownList1.SelectedValue.ToString();
        objects.state = DropDownList2.SelectedValue.ToString();
        objects.role = DropDownList3.SelectedValue.ToString();
        Class.Class1 obj1 = new Class.Class1();
         obj1.Ins(objects);




    }
}