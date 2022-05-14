// File:    Prescription.cs
// Author:  jspho
// Created: 2019年5月26日 20:16:25
// Purpose: Definition of Class Prescription

using System;

public class Prescription
{
   public string prescriptionID;
   public DateTime prescriptionTime;
   
   public System.Collections.Generic.List<PrescriptionItem> prescriptionItem;
   
   /// <summary>
   /// Property for collection of PrescriptionItem
   /// </summary>
   /// <pdGenerated>Default opposite class collection property</pdGenerated>
   public System.Collections.Generic.List<PrescriptionItem> PrescriptionItem
   {
      get
      {
         if (prescriptionItem == null)
            prescriptionItem = new System.Collections.Generic.List<PrescriptionItem>();
         return prescriptionItem;
      }
      set
      {
         RemoveAllPrescriptionItem();
         if (value != null)
         {
            foreach (PrescriptionItem oPrescriptionItem in value)
               AddPrescriptionItem(oPrescriptionItem);
         }
      }
   }
   
   /// <summary>
   /// Add a new PrescriptionItem in the collection
   /// </summary>
   /// <pdGenerated>Default Add</pdGenerated>
   public void AddPrescriptionItem(PrescriptionItem newPrescriptionItem)
   {
      if (newPrescriptionItem == null)
         return;
      if (this.prescriptionItem == null)
         this.prescriptionItem = new System.Collections.Generic.List<PrescriptionItem>();
      if (!this.prescriptionItem.Contains(newPrescriptionItem))
      {
         this.prescriptionItem.Add(newPrescriptionItem);
         newPrescriptionItem.Prescription = this;
      }
   }
   
   /// <summary>
   /// Remove an existing PrescriptionItem from the collection
   /// </summary>
   /// <pdGenerated>Default Remove</pdGenerated>
   public void RemovePrescriptionItem(PrescriptionItem oldPrescriptionItem)
   {
      if (oldPrescriptionItem == null)
         return;
      if (this.prescriptionItem != null)
         if (this.prescriptionItem.Contains(oldPrescriptionItem))
         {
            this.prescriptionItem.Remove(oldPrescriptionItem);
            oldPrescriptionItem.Prescription = null;
         }
   }
   
   /// <summary>
   /// Remove all instances of PrescriptionItem from the collection
   /// </summary>
   /// <pdGenerated>Default removeAll</pdGenerated>
   public void RemoveAllPrescriptionItem()
   {
      if (prescriptionItem != null)
      {
         System.Collections.ArrayList tmpPrescriptionItem = new System.Collections.ArrayList();
         foreach (PrescriptionItem oldPrescriptionItem in prescriptionItem)
            tmpPrescriptionItem.Add(oldPrescriptionItem);
         prescriptionItem.Clear();
         foreach (PrescriptionItem oldPrescriptionItem in tmpPrescriptionItem)
            oldPrescriptionItem.Prescription = null;
         tmpPrescriptionItem.Clear();
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