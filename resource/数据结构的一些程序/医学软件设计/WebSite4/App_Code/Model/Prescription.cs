// File:    Prescription.cs
// Author:  jsphone
// Created: 2020年5月13日 20:54:29
// Purpose: Definition of Class Prescription

using System;


public class Prescription
{
       private    string  _prescriptionId;
       public string prescriptionId
       {
           get 
           {
              return _prescriptionId;
           }
           set
           {
               _prescriptionId=value;
           }
       }
       private    DateTime  _prescriptionTime;
       public DateTime prescriptionTime
       {
           get 
           {
              return _prescriptionTime;
           }
           set
           {
               _prescriptionTime=value;
           }
       }
   
   public System.Collections.Generic.List<Prescriptionitem> prescriptionitem;
   
   /// <summary>
   /// Property for collection of Prescriptionitem
   /// </summary>
   /// <pdGenerated>Default opposite class collection property</pdGenerated>
   public System.Collections.Generic.List<Prescriptionitem> Prescriptionitem
   {
      get
      {
         if (prescriptionitem == null)
            prescriptionitem = new System.Collections.Generic.List<Prescriptionitem>();
         return prescriptionitem;
      }
      set
      {
         RemoveAllPrescriptionitem();
         if (value != null)
         {
            foreach (Prescriptionitem oPrescriptionitem in value)
               AddPrescriptionitem(oPrescriptionitem);
         }
      }
   }
   
   /// <summary>
   /// Add a new Prescriptionitem in the collection
   /// </summary>
   /// <pdGenerated>Default Add</pdGenerated>
   public void AddPrescriptionitem(Prescriptionitem newPrescriptionitem)
   {
      if (newPrescriptionitem == null)
         return;
      if (this.prescriptionitem == null)
         this.prescriptionitem = new System.Collections.Generic.List<Prescriptionitem>();
      if (!this.prescriptionitem.Contains(newPrescriptionitem))
      {
         this.prescriptionitem.Add(newPrescriptionitem);
         newPrescriptionitem.Prescription = this;
      }
   }
   
   /// <summary>
   /// Remove an existing Prescriptionitem from the collection
   /// </summary>
   /// <pdGenerated>Default Remove</pdGenerated>
   public void RemovePrescriptionitem(Prescriptionitem oldPrescriptionitem)
   {
      if (oldPrescriptionitem == null)
         return;
      if (this.prescriptionitem != null)
         if (this.prescriptionitem.Contains(oldPrescriptionitem))
         {
            this.prescriptionitem.Remove(oldPrescriptionitem);
            oldPrescriptionitem.Prescription = null;
         }
   }
   
   /// <summary>
   /// Remove all instances of Prescriptionitem from the collection
   /// </summary>
   /// <pdGenerated>Default removeAll</pdGenerated>
   public void RemoveAllPrescriptionitem()
   {
      if (prescriptionitem != null)
      {
         System.Collections.ArrayList tmpPrescriptionitem = new System.Collections.ArrayList();
         foreach (Prescriptionitem oldPrescriptionitem in prescriptionitem)
            tmpPrescriptionitem.Add(oldPrescriptionitem);
         prescriptionitem.Clear();
         foreach (Prescriptionitem oldPrescriptionitem in tmpPrescriptionitem)
            oldPrescriptionitem.Prescription = null;
         tmpPrescriptionitem.Clear();
      }
   }
   public Patient patient;
   
   /// <summary>
   /// Property for Patient
   /// </summary>
   /// <pdGenerated>Default opposite class property</pdGenerated>
   public Patient Patient
   {
      get
      {
         return patient;
      }
      set
      {
         if (this.patient == null || !this.patient.Equals(value))
         {
            if (this.patient != null)
            {
               Patient oldPatient = this.patient;
               this.patient = null;
               oldPatient.RemovePrescription(this);
            }
            if (value != null)
            {
               this.patient = value;
               this.patient.AddPrescription(this);
            }
         }
      }
   }
   public Doctor doctor;
   
   /// <summary>
   /// Property for Doctor
   /// </summary>
   /// <pdGenerated>Default opposite class property</pdGenerated>
   public Doctor Doctor
   {
      get
      {
         return doctor;
      }
      set
      {
         if (this.doctor == null || !this.doctor.Equals(value))
         {
            if (this.doctor != null)
            {
               Doctor oldDoctor = this.doctor;
               this.doctor = null;
               oldDoctor.RemovePrescription(this);
            }
            if (value != null)
            {
               this.doctor = value;
               this.doctor.AddPrescription(this);
            }
         }
      }
   }

}