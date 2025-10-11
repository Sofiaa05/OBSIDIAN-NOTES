- using array to loop through all the cards
```js

import React from 'react';
import { ArrowLeft, Check } from 'lucide-react';

const plans = [
  {
    title: 'Free',
    price: '$0',
    per: '/month',
    description: 'Limited features included',
    features: ['1 Workstream', 'Up to 2 SDRs', '5 Associates', 'Basic project management', 'Email support'],
    buttonText: 'Downgrade',
    buttonClass: 'border-[#D1D5DB] text-[#374151] bg-white',
  },
  {
    title: 'Basic',
    price: '$100',
    per: '/month',
    features: ['3 Workstreams', 'Up to 5 SDRs', '15 Associates', 'Advanced project tools', 'Priority support', 'Basic analytics'],
    buttonText: 'Active Plan',
    buttonClass: 'bg-[#F3F4F6] text-[#22C55E] border-[#E5E7EB]',
  },
  {
    title: 'Standard',
    price: '$200',
    per: '/month',
    features: ['10 Workstreams', 'Up to 15 SDRs', '50 Associates', 'Client facing features', 'Group chat & payments', 'Advanced analytics'],
    buttonText: 'Choose Standard',
    buttonClass: 'bg-[#FF6646] text-white border-[#E5E7EB]',
    recommended: true,
  },
  {
    title: 'Enterprise',
    price: 'Contact Us',
    per: '',
    features: ['Unlimited Workstreams', 'Unlimited SDRs', 'Unlimited Associates', 'Custom Integrations', 'Dedicated support', 'White-label options'],
    buttonText: 'Contact Sales',
    buttonClass: 'border-[#D1D5DB] text-[#374151] bg-white',
  },
];

const Payments = () => {
  const handleBack = () => console.log("Navigating back to membership");

  return (
    <div className="px-4 md:px-16">
      {/* Header */}
      <div className="max-w-7xl h-36 mt-8 md:mt-9 rounded-xl border border-gray-200 bg-white shadow-sm p-6 md:p-8">
        <div className="flex items-center gap-x-1 cursor-pointer" onClick={handleBack}>
          <ArrowLeft className="w-6 h-5 text-[#6B7280]" />
          <p className="font-[Karla] text-[14px] leading-[14px] font-medium text-[#6B7280]">Back to Membership</p>
        </div>
        <h1 className="mt-3 font-[Karla] font-normal text-lg md:text-2xl leading-[24px] text-[#111827]">
          Choose Your Perfect Plan
        </h1>
        <p className="mt-3 font-[Karla] font-normal text-[16px] leading-[16px] text-[#4B5563] max-w-full md:max-w-[637px]">
          Select the subscription plan that best fits your agency's needs and scale as you grow.
        </p>
      </div>

      {/* Cards */}
      <div className="max-w-7xl mt-4 flex flex-wrap gap-5 justify-start">
        {plans.map((plan, idx) => (
          <div
            key={idx}
            className={`w-full sm:w-[48%] md:w-[266px] min-h-[520px] rounded-xl flex flex-col p-4 sm:p-6 relative
              ${plan.recommended ? 'border-2 border-[#FF6646] shadow-lg bg-white' : 'border border-[#E5E7EB] shadow-sm bg-white'}`}
          >
            {plan.recommended && (
              <div className="absolute -top-3 left-6 w-[206px] h-7 rounded-full bg-[#FF6646] flex items-center justify-center text-white font-[Karla] text-[14px]">
                Recommended by Workfall
              </div>
            )}

            <p className="font-[Karla] font-normal text-[20px] leading-[28px] text-[#111827]">{plan.title}</p>

            {plan.description && (
              <p className="mt-2 font-[Karla] font-normal text-[14px] leading-[16px] text-[#6B7280]">{plan.description}</p>
            )}

            {plan.title !== 'Enterprise' && (
              <div className="flex gap-x-2 mt-2 items-end">
                <h1 className="font-[Karla] font-normal text-2xl sm:text-3xl leading-[36px] text-[#111827]">{plan.price}</h1>
                <p className="font-[Karla] font-normal text-[16px] leading-[24px] text-[#6B7280]">{plan.per}</p>
              </div>
            )}

            {plan.title === 'Enterprise' && (
              <h1 className="mt-4 font-[Karla] font-normal text-[24px] leading-[32px] text-[#111827]">{plan.price}</h1>
            )}

            <ul className="mt-5 space-y-3 flex-1">
              {plan.features.map((feature, i) => (
                <li key={i} className="flex gap-2 text-[#374151] items-start">
                  <Check className="w-6 h-5 mt-[3px] text-[#22C55E]" />
                  {feature}
                </li>
              ))}
            </ul>

            <button className={`w-full sm:w-[90%] h-12 mt-4 rounded-lg font-[Karla] font-normal text-[16px] ${plan.buttonClass}`}>
              {plan.buttonText}
            </button>
          </div>
        ))}
      </div>

      {/* Footer */}
      <div className="w-full max-w-[1184px] h-[58px] mt-24 border-t border-t-[#F3F4F6] flex justify-end items-center px-4 md:px-0">
        <div className="flex flex-col sm:flex-row gap-2">
          <button className="w-[87px] h-10 rounded-xl border border-gray-200 font-[Karla] font-normal text-[16px]">
            Back
          </button>
          <button className="w-[174px] h-10 rounded-xl border border-gray-200 font-[Karla] font-normal text-[16px] bg-[#FF6646] text-white">
            Save Changes
          </button>
        </div>
      </div>
    </div>
  );
};

export default Payments;

```

## hardcoded for every card
```js
import React from 'react';
import { ArrowLeft } from 'lucide-react';
import { Check } from 'lucide-react';

const Payments = () => {
  const handleback = () => {
    console.log("Navigating back to membership");
  }

  return (
    <div>
    {/*first div */}
    <div className="max-w-7xl h-36 mt-8 md:mt-37 ml-4 md:ml-70 rounded-xl border border-gray-200 bg-white shadow-sm">
      {/* back to membership link */}
        <div className="max-w-5xl mt-6 ml-8 flex items-center gap-x-1" onClick={handleback}>
            <ArrowLeft className="w-6 h-5 text-[#6B7280]"/>
            <p className='font-[Karla] text-[14px] leading-[14px] tracking-[0px] font-medium text-[#6B7280]'>Back to Membership</p>
        </div>

        <h1 className="max-w-[287px] mt-3 ml-8 font-[Karla] font-normal text-lg md:text-2xl leading-[24px] tracking-[0px] text-[#111827]">Choose Your Perfect Plan</h1>

        <p className="max-w-[637px] mt-3 ml-8 font-[Karla] font-normal text-[16px] leading-[16px] tracking-[0px] text-[#4B5563]">
            Select the subscription plan that best fits your agency's needs and scale as you grow.
        </p>
    </div >
    {/* Second div for cards*/}
    <div className="max-w-7xl mt-4 ml-4 md:ml-70 flex flex-wrap gap-5">

     {/* CARD 1 */}
      <div className='w-full sm:w-[48%] md:w-[266px] min-h-[520px]  rounded-xl border border-[#E5E7EB] shadow-sm'>
       
        <div className='w-full min-h-[422px] ml-2 sm:ml-6 mt-2 sm:mt-6'>
          <p className='font-[Karla] font-normal text-[20px] leading-[28px] tracking-[0px] text-[#111827]'>Free</p>
          <p className='mt-2 font-[Karla] font-normal text-[14px] leading-[100%] tracking-[0px] text-[#6B7280]'>Limited features included</p>
          
          <div className='flex gap-x-2 mt-2'>
            <h1 className='font-[Karla] font-normal text-2xl sm:text-3xl leading-[36px] tracking-[0px] text-[#111827]'>$0</h1>
            <p className='mt-3 font-[Karla] font-normal text-[16px] leading-[24px] tracking-[0px] text-[#6B7280]'>/month</p>
          </div>

          {/* Listing */}
          <ul className='w-full mt-5 space-y-3 h-52 mt-5'>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>1 Workstream</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Up to 2 SDRs</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>5 Associates</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Basic project management</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Email support</li>
          </ul>

          <button className='w-full sm:w-[80%] h-12 mt-[90px] rounded-lg border border-[#D1D5DB] font-[Karla] font-normal text-[16px] leading-[100%] tracking-[0] text-center text-[#374151]'>Downgrade</button>
        </div>
      </div>

        {/* Card 2 */}
      <div className='w-full sm:w-[48%] md:w-[266px] min-h-[520px] rounded-xl border border-[#E5E7EB] shadow-sm'>
       
        <div className='w-full min-h-[422px] ml-2 sm:ml-6 mt-2 sm:mt-6'>
          <p className='font-[Karla] font-normal text-[20px] leading-[28px] tracking-[0px] text-[#111827]'>Basic</p>
          
          <div className='flex gap-x-2 mt-2'>
            <h1 className='font-[Karla] font-normal text-2xl sm:text-3xl leading-[36px] tracking-[0px] text-[#111827]'>$100</h1>
            <p className='mt-3 font-[Karla] font-normal text-[16px] leading-[24px] tracking-[0px] text-[#6B7280]'>/month</p>
          </div>

          {/* Listing */}
          <ul className='w-full mt-5 space-y-3 h-52 mt-5'>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>3 Workstreams</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Up to 5 SDRs</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>15 Associates</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Advanced project tools</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Priority support</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Basic analytics</li>
          </ul>

          <button className='w-full sm:w-[80%] h-12 mt-[112px] rounded-[8px] border border-[#E5E7EB] font-[Karla] font-normal text-[16px] bg-[#F3F4F6] leading-[100%] tracking-[0px] text-[#22C55E]'>Active Plan</button>
        </div>
      </div>

      {/* Card 3 */}
      <div className='w-full sm:w-[48%] md:w-[266px] min-h-[520px] rounded-xl border-[#FF6646] border-[2px] shadow-lg bg-white'>

        <div className='w-[206px] h-7 mt-[-10px] ml-6 rounded-[9999px] bg-[#FF6646] font-[karla] font-normal text-[14px] leading-[100%] text-center text-[#FFFFFF] p-2'>Recommended by Workfall</div>
       
        <div className='max-w-[216px] h-422px] mt-2 ml-6'>
          <p className='font-[Karla] font-normal text-[20px] leading-[28px] tracking-[0px] text-[#111827]'>Standard</p>
          
          <div className='flex gap-x-2 mt-2'>
            <h1 className='font-[Karla] font-normal ttext-2xl sm:text-3xl leading-[36px] tracking-[0px] text-[#111827]'>$200</h1>
            <p className='mt-3 font-[Karla] font-normal text-[16px] leading-[24px] tracking-[0px] text-[#6B7280]'>/month</p>
          </div>

          {/* Listing */}
          <ul className='w-full mt-5 space-y-3 h-52 mt-5'>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>10 Workstreams</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Up to 15 SDRs</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>50 Associates</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Client facing features</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Group chat & payments</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Advanced analytics</li>
          </ul>

          <button className='w-full sm:w-[80%] h-12 mt-[112px] rounded-[8px] border border-[#E5E7EB] font-[Karla] font-normal text-[16px] bg-[#FF6646] leading-[100%] tracking-[0px] text-[#FFFFFF]'>Choose Standard</button>
        </div>
      </div>

{/* CARD 4 */}
      <div className='w-full sm:w-[48%] md:w-[266px] min-h-[520px] rounded-xl border border-[#E5E7EB] shadow-sm'>
       
        <div className='w-full min-h-[422px] ml-2 sm:ml-6 mt-2 sm:mt-6'>
          <p className='font-[Karla] font-normal text-[20px] leading-[28px] tracking-[0px] text-[#111827]'>Enterprise</p>
          
          <div className='mt-4'>
            <h1 className='font-[Karla] font-normal text-[24px] leading-[32px] tracking-[0px] text-[#111827]'>Contact Us</h1>
          </div>

          {/* Listing */}
          <ul className='w-full mt-5 space-y-3 h-57 mt-5'>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Unlimited Workstreams</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Unlimited SDRs</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Unlimited Associates</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Custom Integrations</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>Dedicated support</li>
            <li className='mt-3 flex gap-2 text-[#374151]'><Check className='w-6 h-5 mt-[3px] text-[#22C55E]'/>White-label options</li>
          </ul>

          <button className='w-full sm:w-[80%] h-12 mt-[120px] rounded-[8px] border border-[#D1D5DB] font-[Karla] font-normal text-[16px] leading-[100%] tracking-[0px] item-center text-[#374151]'>Contact Sales</button>
        </div>
      </div>
    </div>

      {/* footer div */}
        <div className="w-full max-w-[1184px] h-[58px] mt-24 border-t border-t-[#F3F4F6]">
          <div className="w-full max-w-[273px] h-[40px] mt-2 ml-auto mr-4 flex flex-col sm:flex-row gap-2">
            <button className="w-[87px] h-10 mt-2 rounded-xl  border border-gray-200 font-[Karla] font-normal text-[16px] leading-[16px] tracking-[0px]">Back</button>
            <button className="w-[174px] h-10 mt-2 rounded-xl  border border-gray-200 font-[Karla] font-normal text-[16px] leading-[16px] tracking-[0px] bg-[#FF6646] text-white">Save Changes</button>
          </div>
        </div>
    </div>
  );
};

export default Payments;




```