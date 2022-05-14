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
using System.Data.OleDb;
/// <summary>
///patientDA 的摘要说明
/// </summary>
public class patientDA
{
	public patientDA()
	{
		//
		//TODO: 在此处添加构造函数逻辑
		//
	}
    public DataSet GetAllPatient()
    {
        OleDbConnection conn = new OleDbConnection();
        conn.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0; Data Source=F:\\HIS.mdb; User Id=admin; Password=";
        conn.Open();
        OleDbDataAdapter ad = new OleDbDataAdapter("select PatientId as 编号,PatientName as 姓名,PatientSex as 性别,PatientAddress as 住址,PatientPhone as 电话,PatientBirthday as 生日 from Patient", conn);
        DataSet dt = new DataSet();
        ad.Fill(dt);
        conn.Close();
        return dt;
    }

    public void DeletebyId(String id)
    {
        OleDbConnection conn = new OleDbConnection();
        conn.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0; Data Source=F:\\HIS.mdb; User Id=admin; Password=";
        conn.Open();
        OleDbCommand comm = new OleDbCommand();
        comm.Connection = conn;
        comm.CommandText = "delete from patient where PatientId=@Pid";
        comm.Parameters.Add("Pid", OleDbType.Char, 10);
        comm.Parameters[0].Value = id;
        comm.ExecuteNonQuery();
        conn.Close();
    }
    public DataSet GetbyId(String id)
    {
        OleDbConnection conn = new OleDbConnection();
        conn.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0; Data Source=F:\\HIS.mdb; User Id=admin; Password=";
        conn.Open();
        OleDbCommand comm = new OleDbCommand();
        comm.Connection = conn;
        comm.CommandText = "select * from patient where PatientId=@Pid";
        comm.Parameters.Add("Pid", OleDbType.Char, 10);
        comm.Parameters[0].Value = id;
        OleDbDataAdapter ad = new OleDbDataAdapter();
        ad.SelectCommand = comm;
        DataSet ds = new DataSet();
        ad.Fill(ds);
        conn.Close();
        return ds;
    }

    public void Insert(Patient pt)
    {
        OleDbConnection conn = new OleDbConnection();
        conn.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0; Data Source=F:\\HIS.mdb; User Id=admin; Password=";
        conn.Open();
        OleDbCommand comm = new OleDbCommand();
        comm.Connection = conn;
        comm.CommandText = "insert into Patient (PatientId,PatientName,PatientSex,PatientAddress,PatientPhone,PatientBirthday) values (@Pid,@Pname,@Psex,@Paddress,@Pphone,@Pbirth)";
        comm.Parameters.Add("Pid", OleDbType.Char, 10);
        comm.Parameters.Add("Pname", OleDbType.Char, 10);
        comm.Parameters.Add("Psex", OleDbType.Char, 1);
        comm.Parameters.Add("Paddress", OleDbType.Char, 20);
        comm.Parameters.Add("Pphone", OleDbType.Char, 15);
        comm.Parameters.Add("Pbirth", OleDbType.Date);
        comm.Parameters[0].Value = pt.patientId;
        comm.Parameters[1].Value = pt.patientName;
        comm.Parameters[2].Value = pt.patientSex;
        comm.Parameters[3].Value = pt.patientAddress;
        comm.Parameters[4].Value = pt.patientPhone;
        comm.Parameters[5].Value = pt.patientBirthday;
        comm.ExecuteNonQuery();
        conn.Close();
        
    }

    public void UpdateById(Patient pt)
    {
        OleDbConnection conn = new OleDbConnection();
        conn.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0; Data Source=F:\\HIS.mdb; User Id=admin; Password=";
        conn.Open();
        OleDbCommand comm = new OleDbCommand();
        comm.Connection = conn;
        comm.CommandText = "update Patient set PatientName=@Pname,PatientSex=@Psex,PatientPhone=@Pphone,PatientAddress=@Paddress,PatientBirthday=@Pbirth where PatientId=@Pid";
        comm.Parameters.Add("Pname", OleDbType.Char, 10);
        comm.Parameters.Add("Psex", OleDbType.Char, 1);
        comm.Parameters.Add("Paddress", OleDbType.Char, 20);
        comm.Parameters.Add("Pphone", OleDbType.Char, 15);
        comm.Parameters.Add("Pbirth", OleDbType.Date);
        comm.Parameters.Add("Pid", OleDbType.Char, 10);
        comm.Parameters[5].Value = pt.patientId;
        comm.Parameters[0].Value = pt.patientName;
        comm.Parameters[1].Value = pt.patientSex;
        comm.Parameters[2].Value = pt.patientAddress;
        comm.Parameters[3].Value = pt.patientPhone;
        comm.Parameters[4].Value = pt.patientBirthday;
        comm.ExecuteNonQuery();
        conn.Close();

    }

    public String GetbyIdIsIn(String id)
    {
        OleDbConnection conn = new OleDbConnection();
        conn.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0; Data Source=F:\\HIS.mdb; User Id=admin; Password=";
        conn.Open();
        OleDbCommand comm = new OleDbCommand();
        comm.Connection = conn;
        comm.CommandText = "select count(*) from patient where PatientId=@Pid";
        comm.Parameters.Add("Pid", OleDbType.Char, 10);
        comm.Parameters[0].Value = id;
        String n=comm.ExecuteScalar().ToString();
        conn.Close();
        return n;
    }
    public DataSet GetBySQLstr(String str)
    {
        OleDbConnection conn = new OleDbConnection();
        conn.ConnectionString = "Provider=Microsoft.Jet.OLEDB.4.0; Data Source=F:\\HIS.mdb; User Id=admin; Password=";
        conn.Open();
        OleDbDataAdapter ad = new OleDbDataAdapter(str, conn);
        DataSet dt = new DataSet();
        ad.Fill(dt);
        conn.Close();
        return dt;
    }
}
