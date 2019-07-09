using System;
using System.Collections.Generic;
using System.Linq;

namespace ArchitectureLab1.Extensions
{
    static class TypeExtensions
    {
        public static string GetConstructorsString(this Type type)
        {
            string constructors = string.Empty;

            foreach (var constructor in type.GetConstructors().ToList())
            {
                List<string> parameters = new List<string>();
                foreach (var parametr in constructor.GetParameters().ToList())
                {
                    parameters.Add($"{parametr.ParameterType.Name} {parametr.Name}");
                }

                constructors += $"{type.GetModifiersString()} {type.Name}({String.Join(", ", parameters)});\n";
            }

            return constructors;
        }

        /// <summary>
        /// Get string which consist of modifiers and name of class which get by reflection
        /// </summary>
        public static string GetModifiersString(this Type type)
        {
            string classModifiers = type.IsPublic ? "public " : "private ";
            classModifiers += type.IsSealed ? "sealed " : "";

            return classModifiers;
        }
    }
}