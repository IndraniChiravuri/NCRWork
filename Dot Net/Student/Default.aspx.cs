using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void add_Click(object sender, EventArgs e)
    {
        SqlConnection con = new SqlConnection("Data Source=DESKTOP-DGAB2KA;Initial Catalog=aspclass;Integrated Security=True");
        con.Open();
        string procedure_name = "addStudent";
        SqlCommand command = new SqlCommand(procedure_name, con);
        SqlParameter _name = new SqlParameter("@name", name.Text);
        command.Parameters.Add(_name);
        SqlParameter _rollNo = new SqlParameter("@rollNo", rollNo.Text);
        command.Parameters.Add(_rollNo);
        SqlParameter _year = new SqlParameter("@year", year.Text);
        command.Parameters.Add(_year);
        SqlParameter _branch = new SqlParameter("@branch", branch.Text);
        command.Parameters.Add(_branch);
        command.CommandType = System.Data.CommandType.StoredProcedure;
        command.ExecuteNonQuery();
        con.Close();
    }

    protected void show_Click(object sender, EventArgs e)
    {
        SqlConnection con = new SqlConnection("Data Source=DESKTOP-DGAB2KA;Initial Catalog=aspclass;Integrated Security=True");
        con.Open();
        string procedure_name = "getStudents";
        SqlCommand cmd = new SqlCommand(procedure_name, con);
        cmd.CommandType = System.Data.CommandType.StoredProcedure;
        SqlDataReader dr = cmd.ExecuteReader();
        result.DataSource = dr;
        result.DataBind();
        con.Close();
    }

    protected void reset_Click(object sender, EventArgs e)
    {
        name.Text = " ";
        rollNo.Text = " ";
        year.Text = " ";
        branch.Text = " ";
    }

    protected void delete_Click(object sender, EventArgs e)
    {
        SqlConnection con = new SqlConnection("Data Source=DESKTOP-DGAB2KA;Initial Catalog=aspclass;Integrated Security=True");
        con.Open();
        string procedure_name = "deleteStudent";
        SqlCommand command = new SqlCommand(procedure_name, con);
        command.CommandType = System.Data.CommandType.StoredProcedure;
        SqlParameter _name = new SqlParameter("@name", name.Text);
        command.Parameters.Add(_name);
        SqlParameter _rollNo = new SqlParameter("@rollNo", rollNo.Text);
        command.Parameters.Add(_rollNo);
        SqlParameter _year = new SqlParameter("@year", year.Text);
        command.Parameters.Add(_year);
        SqlParameter _branch = new SqlParameter("@branch", branch.Text);
        command.Parameters.Add(_branch);
        command.ExecuteNonQuery();
        con.Close();
    }

    protected void update_Click(object sender, EventArgs e)
    {
        SqlConnection con = new SqlConnection("Data Source=DESKTOP-DGAB2KA;Initial Catalog=aspclass;Integrated Security=True");
        con.Open();
        string procedure_name = "updateStudent";
        SqlCommand command = new SqlCommand(procedure_name, con);
        command.CommandType = System.Data.CommandType.StoredProcedure;
        SqlParameter _name = new SqlParameter("@name", name.Text);
        command.Parameters.Add(_name);
        SqlParameter _rollNo = new SqlParameter("@rollNo", rollNo.Text);
        command.Parameters.Add(_rollNo);
        SqlParameter _year = new SqlParameter("@year", year.Text);
        command.Parameters.Add(_year);
        SqlParameter _branch = new SqlParameter("@branch", branch.Text);
        command.Parameters.Add(_branch);
        command.ExecuteNonQuery();
        con.Close();
    }
}