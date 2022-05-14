using System;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;

public partial class _Default : System.Web.UI.Page 
{
    protected void Page_Load(object sender, EventArgs e)
    {
        binddata();
    }
    private void binddata()
    {
        patientBLL bll = new patientBLL();
        DataSet pt = new DataSet();
        pt = bll.GetAllPatient();
        this.GridView1.DataSource = pt;
        this.GridView1.DataBind();
    }
    protected void GridView1_SelectedIndexChanging(object sender, GridViewSelectEventArgs e)
    {
        String id;
        id = this.GridView1.DataKeys[e.NewSelectedIndex].Value.ToString().Trim();
        patientBLL bll = new patientBLL();
        DataSet ds = new DataSet();
        ds=bll.GetById(id);
        DataTable dt = ds.Tables[0];
        DataRow dr = dt.Rows[0];
        this.TextBox1.Text = dr[0].ToString().Trim();
        this.TextBox2.Text = dr[1].ToString().Trim();
        this.TextBox3.Text = dr[2].ToString().Trim();
        this.TextBox4.Text = dr[4].ToString().Trim();
        this.TextBox5.Text = dr[3].ToString().Trim();
        this.TextBox6.Text = dr[5].ToString().Trim();
        this.Button1.Text = "修改";
    }
    protected void GridView1_RowDeleting(object sender, GridViewDeleteEventArgs e)
    {
        String id;
        id = this.GridView1.DataKeys[e.RowIndex].Value.ToString().Trim();
        patientBLL bll = new patientBLL();
        bll.DeleteById(id);
        binddata();
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        Patient pt = new Patient();
        pt.patientId = this.TextBox1.Text.Trim();
        pt.patientName = this.TextBox2.Text.Trim();
        pt.patientSex = this.TextBox3.Text.Trim();
        pt.patientAddress = this.TextBox4.Text.Trim();
        pt.patientPhone = this.TextBox5.Text.Trim();
        pt.patientBirthday = Convert.ToDateTime(this.TextBox6.Text.Trim());
        patientBLL bll = new patientBLL();
        String n = bll.IsinByid(pt.patientId);
        if (n == "0")
            bll.Insert(pt);
        else
            bll.UpdateByid(pt);
        binddata();
        ClientScript.RegisterClientScriptBlock(this.GetType(), "ok", "alert('添加成功！')", true);
    }
    protected void Button2_Click(object sender, EventArgs e)
    {
        Patient pt = new Patient();
        pt.patientId = this.TextBox1.Text.Trim();
        pt.patientName = this.TextBox2.Text.Trim();
        pt.patientSex = this.TextBox3.Text.Trim();
        pt.patientAddress = this.TextBox4.Text.Trim();
        pt.patientPhone = this.TextBox5.Text.Trim();
        //pt.patientBirthday = Convert.ToDateTime(this.TextBox6.Text.Trim());
        patientBLL bll = new patientBLL();
        DataSet ds = new DataSet();
        ds=bll.QueryPatient(pt);
        this.GridView1.DataSource = ds;
        this.GridView1.DataBind();
    }
}
