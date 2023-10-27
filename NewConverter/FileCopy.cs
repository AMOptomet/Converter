using ManagedLayer;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace WPF_CopyFileWithProgressBar
{
    public sealed class FileModel
    {
        private static FileModel instance = null;
        private static readonly object padlock = new object();
        public static FileModel Instance
        {
            get
            {
                lock (padlock)
                {
                    if (instance == null)
                    {
                        instance = new FileModel();
                    }
                    return instance;
                }
            }


        }
        


        public void OnConvert(string source, string destin)
        {

           
            

            tc.Converting(source, destin);
        }


    };
}