// File:    Patient.cs
// Author:  jspho
// Created: 2019年5月26日 20:16:25
// Purpose: Definition of Class Patient

using System;

public class Patient
{
   public string patientId;
   public string patientName;
   public string patientSex;
   public string patientPhone;
   public string patientAddress;
   public DateTime patientBirthday;
   
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
         newPrescription.Patient = this;
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
            oldPrescription.Patient = null;
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
            oldPrescription.Patient = null;
         tmpPrescription.Clear();
      }
   }

}