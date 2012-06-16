﻿using System;
using System.Collections.Generic;
using System.Xml;
using DoxygenWrapper.Wrappers.Compounds.Types;

namespace DoxygenWrapper.Wrappers.Compounds
{
	public class CompoundFunction :
		Compound
	{
		protected override void OnParse(XmlNode _node)
		{
			base.OnParse(_node);

			mCompoundType = new CompoundType(_node["type"], _node["name"].Value);
			foreach (XmlNode node in _node.SelectNodes("param"))
				mCompoundParamTypes.Add(new CompoundType(node["type"], node["declname"] != null ? node["declname"].Value : ""));

			mPublic = _node.Attributes["prot"].Value == "public";
			mStatic = _node.Attributes["static"].Value == "yes";
		}

		public CompoundType CompoundType
		{
			get { return mCompoundType; }
		}

		public List<CompoundType>.Enumerator CompoundParamTypes
		{
			get { return mCompoundParamTypes.GetEnumerator(); }
		}

		public bool Public
		{
			get { return mPublic; }
		}

		public bool Static
		{
			get { return mStatic; }
		}

		private CompoundType mCompoundType;
		private List<CompoundType> mCompoundParamTypes = new List<CompoundType>();
		private bool mPublic;
		private bool mStatic;
	}
}