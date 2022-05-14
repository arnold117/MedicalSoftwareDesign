using System;
using System.Data;
using System.Configuration;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.HtmlControls;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Xml.Linq;

/// <summary>
///patientBLL 的摘要说明
/// </summary>
public class patientBLL
{
	public patientBLL()
	{
		//
		//TODO: 在此处添加构造函数逻辑
		//
	}
    public DataSet GetAllPatient()
    {
        patientDA da = new patientDA();
        return da.GetAllPatient();
    }

    public void DeleteById(String id)
    {
        patientDA da = new patientDA();
        da.DeletebyId(id);
    }

    public DataSet GetById(String id)
    {
        patientDA da = new patientDA();
        return da.GetbyId(id);
    }

    public void Insert(Patient pt)
    {
        patientDA da = new patientDA();
        da.Insert(pt);
    }
    public void UpdateByid(Patient pt)
    {
        patientDA da = new patientDA();
        da.UpdateById(pt);
    }

    public String IsinByid(String id)
    {
        patientDA da = new patientDA();
        return da.GetbyIdIsIn(id);
    }

    public DataSet QueryPatient(Patient pt)
    {
        String sqlstr = "select PatientId as 编号,PatientName as 姓名,PatientSex as 性别,PatientAddress as 住址,PatientPhone as 电话,PatientBirthday as 生日 from Patient where";
        int n=0;
        if (pt.patientId.Length>0)
        {
            if (n>0) sqlstr=sqlstr+" and";
            sqlstr=sqlstr+" PatientId="+ "'" +pt.patientId+"'";
            n=n+1;
        }
        if (pt.patientName.Length > 0)
        {
            if (n > 0) sqlstr = sqlstr + " and";
            sqlstr = sqlstr + " PatientName=" + "'" + pt.patientName + "'";
            n = n + 1;
        }
        if (n == 0) sqlstr = "select PatientId as 编号,PatientName as 姓名,PatientSex as 性别,PatientAddress as 住址,PatientBirthday as 生日 from Patient";
        patientDA da=new patientDA();
        return da.GetBySQLstr(sqlstr);
    }

}
