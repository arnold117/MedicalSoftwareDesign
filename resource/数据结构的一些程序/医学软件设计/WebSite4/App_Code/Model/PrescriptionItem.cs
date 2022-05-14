// File:    Prescriptionitem.cs
// Author:  jsphone
// Created: 2020年5月13日 20:54:29
// Purpose: Definition of Class Prescriptionitem

using System;


public class Prescriptionitem
{
       private    string  _prescriptionitemId;
       public string prescriptionitemId
       {
           get 
           {
              return _prescriptionitemId;
           }
           set
           {
               _prescriptionitemId=value;
           }
       }
       private    string  _prescriptionItem;
       public string prescriptionItem
       {
           get 
           {
              return _prescriptionItem;
           }
           set
           {
               _prescriptionItem=value;
           }
       }
   
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
               oldPrescription.RemovePrescriptionitem(this);
            }
            if (value != null)
            {
               this.prescription = value;
               this.prescription.AddPrescriptionitem(this);
            }
         }
      }
   }

}