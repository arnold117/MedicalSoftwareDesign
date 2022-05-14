// File:    PrescriptionItem.cs
// Author:  jspho
// Created: 2019年5月26日 20:16:25
// Purpose: Definition of Class PrescriptionItem

using System;

public class PrescriptionItem
{
   public string prescriptionItemID;
   public string prescriptionItem;
   
   public Prescription prescription;
   
   /// <summary>
   /// Property for Prescription
   /// </summary>
   /// <pdGenerated>Default opposite class property</pdGenerated>
   public Prescription Prescription
   {
      get
      {
         return prescription;
      }
      set
      {
         if (this.prescription == null || !this.prescription.Equals(value))
         {
            if (this.prescription != null)
            {
               Prescription oldPrescription = this.prescription;
               this.prescription = null;
               oldPrescription.RemovePrescriptionItem(this);
            }
            if (value != null)
            {
               this.prescription = value;
               this.prescription.AddPrescriptionItem(this);
            }
         }
      }
   }

}