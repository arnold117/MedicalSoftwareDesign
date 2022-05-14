// File:    Doctor.cs
// Author:  jspho
// Created: 2019年5月26日 20:16:25
// Purpose: Definition of Class Doctor

using System;

public class Doctor
{
   public string doctorId;
   public string doctorName;
   public string departmentId;
   public string titleId;
   public DateTime doctorBirthday;
   
   public System.Collections.Generic.List<Prescription> prescription;
   
   /// <summary>
   /// Property for collection of Prescription
   /// </summary>
   /// <pdGenerated>Default opposite class collection property</pdGenerated>
   public System.Collections.Generic.List<Prescription> Prescription
   {
      get
      {
         if (prescription == null)
            prescription = new System.Collections.Generic.List<Prescription>();
         return prescription;
      }
      set
      {
         RemoveAllPrescription();
         if (value != null)
         {
            foreach (Prescription oPrescription in value)
               AddPrescription(oPrescription);
         }
      }
   }
   
   /// <summary>
   /// Add a new Prescription in the collection
   /// </summary>
   /// <pdGenerated>Default Add</pdGenerated>
   public void AddPrescription(Prescription newPrescription)
   {
      if (newPrescription == null)
         return;
      if (this.prescription == null)
         this.prescription = new System.Collections.Generic.List<Prescription>();
      if (!this.prescription.Contains(newPrescription))
      {
         this.prescription.Add(newPrescription);
         newPrescription.Doctor = this;
      }
   }
   
   /// <summary>
   /// Remove an existing Prescription from the collection
   /// </summary>
   /// <pdGenerated>Default Remove</pdGenerated>
   public void RemovePrescription(Prescription oldPrescription)
   {
      if (oldPrescription == null)
         return;
      if (this.prescription != null)
         if (this.prescription.Contains(oldPrescription))
         {
            this.prescription.Remove(oldPrescription);
            oldPrescription.Doctor = null;
         }
   }
   
   /// <summary>
   /// Remove all instances of Prescription from the collection
   /// </summary>
   /// <pdGenerated>Default removeAll</pdGenerated>
   public void RemoveAllPrescription()
   {
      if (prescription != null)
      {
         System.Collections.ArrayList tmpPrescription = new System.Collections.ArrayList();
         foreach (Prescription oldPrescription in prescription)
            tmpPrescription.Add(oldPrescription);
         prescription.Clear();
         foreach (Prescription oldPrescription in tmpPrescription)
            oldPrescription.Doctor = null;
         tmpPrescription.Clear();
      }
   }

}