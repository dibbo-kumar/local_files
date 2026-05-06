# IdeaNest - Complete UI/UX System Design

## Overview

IdeaNest is a modern SaaS platform connecting **Founders**, **Advisors**, and **Investors** in a structured ecosystem for idea feedback and startup funding.

---

## 🎯 Core System Logic

### Role Management

IdeaNest uses **strict role-based access control**:

**Allowed Combinations:**

- ✅ Founder + Investor (user can switch between roles)
- ✅ Advisor + Investor (user can switch between roles)
- ❌ Founder + Advisor (NOT ALLOWED - conflicting interests)

**Dynamic Role Switching:**
When a user changes roles from the top navigation/dashboard, the entire UI adapts:

- Navigation menu updates
- Sidebar resets
- Dashboard displays role-specific content
- Available features change per role

### Profile Completion System

**Incomplete Profile Status:**

- Users who skip profile completion can **ONLY browse**
- Cannot submit ideas, startups, or contact users
- Cannot invest
- Warning banner displays: "Complete your profile to unlock full features"

---

## 📱 Screen Breakdown (11 Screens)

### 1. **Landing Page** (`index.html`)

- **Purpose:** Marketing homepage for new visitors
- **Components:**
  - Hero section with CTA
  - Feature cards (Founders, Advisors, Investors)
  - How it works section
  - Call-to-action section
  - Login/Sign up buttons in navbar
- **Role:** Public (no login required)

### 2. **Login Page** (`pages/login.html`)

- **Purpose:** User authentication
- **Features:**
  - Email/Gmail authentication option
  - Social login (Google)
  - Remember me checkbox
  - Forgot password link
  - Split layout (blue gradient left, white right)
- **Target:** Returning users
- **Responsive:** Mobile-optimized

### 3. **Sign Up Page** (`pages/signup.html`)

- **Purpose:** New user registration
- **Fields:**
  - First Name, Last Name
  - Email (Gmail verification required)
  - Age (18+)
  - Password with strength indicator
  - Confirm Password
  - Terms & Privacy acceptance
- **Next Step:** Redirects to Profile Setup
- **Design:** Modern, clean form with inline validation

### 4. **Profile Setup Page** (`pages/profile-setup.html`)

- **Purpose:** Complete profile after signup
- **Mandatory Steps:**
  1. **Role Selection** - Choose primary role (Founder/Investor/Advisor)
  2. **Skills & Interests** - Add 3-5 relevant skills
  3. **Bio** - Optional 200-300 character bio
- **Options:**
  - Complete Profile (unlocks all features)
  - Skip for Now (limited access with warning)
- **Design:**
  - Progress bar showing completion
  - Visual role descriptions
  - Skill tags with add/remove
  - Clear restrictions notice

---

## 👥 Role-Based Dashboards

### 5. **Founder Dashboard** (`pages/founder-dashboard.html`)

- **Content:**
  - Stats: Total ideas, feedback received, investor interests, active chats
  - Quick action cards: Share Idea, Seek Funding, Connect
  - Recent ideas section (preview list)
  - Role switcher (if eligible)
- **Sidebar Navigation:**
  - Dashboard (active)
  - Submit Idea (Review)
  - Submit Startup (Funding)
  - My Ideas
  - Messages
  - Settings
- **Design:** 250px fixed sidebar + main content grid

### 6. **Advisor Dashboard** (`pages/advisor-dashboard.html`)

- **Content:**
  - Stats: Ideas to review, reviews completed, average rating, active chats
  - Filter section: Category, Sort by, Priority
  - Card-based idea list (NOT investment posts - only review ideas)
  - Each idea shows: title, category, author, views, rating, feedback count
- **Features:**
  - Review button to give feedback
  - Star ratings
  - Priority indicators (High/Medium/Low)
- **Important:** Advisors see ONLY Idea Review posts, NOT Investment posts

### 7. **Investor Dashboard** (`pages/investor-dashboard.html`)

- **Content:**
  - Portfolio stats: Total invested, active investments, portfolio return, startups watched
  - Filter: Industry, Funding Stage, Budget Range
  - View mode toggle (List/Grid)
  - Startup cards (Investment Posts ONLY)
- **Each Startup Card Shows:**
  - Company logo/icon
  - Company name & tagline
  - Team info (location, size, founding date)
  - Industry tags
  - Traction metrics (users, revenue, growth %)
  - Funding amount & stage badge
  - Action buttons: View Details, Save, Connect
- **Important:** Investors see ONLY Investment Posts, NOT Idea Review posts

---

## 📝 Submission Systems (SEPARATE FLOWS)

### **CRITICAL:** Two Different Post Types

#### 8. **Idea Submission - Review Mode** (`pages/founder-submit-idea.html`)

- **Type:** "Idea Review" (seeking feedback only, NO funding asked)
- **Audience:** Advisors only (not visible to investors)
- **Fields:**
  - Idea Title \*
  - Category \* (Technology, Healthcare, E-Commerce, etc.)
  - Problem Statement \* (500 chars)
  - Solution Description \* (500 chars)
  - Target Audience
  - Key Features / USP
  - Full Description (1000 chars)
  - What feedback are you looking for? (checkboxes)
  - Attachments (optional)
- **Design:**
  - Shows comparison table: Idea Review vs Investment
  - Mode indicator badge (blue)
  - Clear distinction from investment posting
- **Output:** Creates "Idea Review" post visible to Advisors

#### 9. **Startup Submission - Investment Mode** (`pages/founder-submit-startup.html`)

- **Type:** "Investment Post" (seeking FUNDING)
- **Audience:** Investors only (not visible to advisors)
- **Fields:**
  - Company Name \*
  - Company Tagline \*
  - Industry \* (dropdown)
  - Founded Date
  - Team Size
  - **Funding Amount Seeking** \* (USD input)
  - **Funding Stage** \* (Seed/Series A/B/C+)
  - How will you use funds?
  - Equity Offered (%)
  - Market Size / TAM \*
  - Business Model \*
  - Traction & Milestones
  - Competitive Advantage
  - Financial Projections (file upload)
  - Business Plan / Pitch Deck (file upload)
  - Email, Phone, LinkedIn
- **Design:**
  - Mode indicator badge (green)
  - Progress steps visualization
  - Financial data emphasis
  - File upload sections
- **Output:** Creates "Investment Post" visible to Investors ONLY

---

## 💬 Interactive Screens

### 10. **Idea Details Page** (`pages/idea-details.html`)

- **Purpose:** View full idea with feedback
- **Layout:** 2-column (main content + sidebar)
- **Main Content:**
  - Full idea description
  - Problem, Solution, Target Audience sections
  - Key features/USP details
  - Traction/results (if available)
- **Feedback Section:**
  - List of all feedback from advisors (8 items shown as example)
  - Each feedback shows: avatar, name, rating, date, comment
  - Feedback form with star rating input
  - Character count for textarea
- **Sidebar:**
  - Rating display (4.5 ⭐ out of 5)
  - Feedback categories breakdown
  - Action buttons: Message, Save Idea, Share
  - Status info: Type, Status, Category
- **Design:** Professional, clean layout with good hierarchy

### 11. **Chat System** (`pages/chat.html`)

- **Layout:** 3-column (sidebar + conversation list + message window)
- **Left Sidebar:** Main navigation (sidebar)
- **Middle Column:**
  - Conversations header with search
  - Chat items list (showing avatar, name, preview, time)
  - Active indicator with blue highlight
- **Right Column (Chat Window):**
  - Chat header with user info & status indicator
  - Call/video buttons
  - Messages container with message bubbles
  - Sent messages (blue, right-aligned)
  - Received messages (white, left-aligned)
  - Timestamps
- **Input Area:**
  - Text input field
  - Attach file button
  - Send button
- **Features:** Type-to-send on Enter, realtime message simulation
- **Use Cases:**
  - Founder ↔ Advisor conversations
  - Founder ↔ Investor conversations

### 12. **My Ideas & Startups** (`pages/founder-ideas.html`)

- **Purpose:** View all founder's submitted ideas/startups
- **Tabs:** All Posts (3), Ideas (1), Startups (2), Drafts (0)
- **Filters:** Type, Status, Sort By
- **Card Layout:**
  - Title with type badge (idea review or investment)
  - Metadata: Submit date, status
  - Description preview
  - Stats: Views, Rating/Investor interests, Feedback/Conversations
  - Actions: View, Edit, Close
- **Status Indicators:** Published, Draft, Closed
- **Pagination:** Previous/Next buttons

### 13. **Admin Panel** (`pages/admin-panel.html`)

- **Purpose:** Platform control & moderation
- **Sections:**
  1. **Dashboard Stats:**
     - Total Users, Pending Verification, Total Ideas, Active Reports
  2. **User Verification Table:**
     - Shows pending Advisor/Investor verifications
     - Status badges: Pending, Approved, Rejected
     - Review/Action buttons
  3. **Reports & Moderation:**
     - Active reports list
     - Report details: ID, reporter, target, reason
     - Action buttons: Review, Remove Content, Ban User
  4. **Platform Statistics:**
     - User breakdown (Founders, Investors, Advisors)
     - Content stats (ideas, startups, feedback)
     - Engagement metrics
- **Design:** Administrative UI with table layouts and action controls

---

## 🎨 Design System

### Color Palette

- **Primary Blue:** `#3B82F6` (accent, CTAs)
- **Primary Dark:** `#1E40AF` (darker blue)
- **Light Gray:** `#F9FAFB` (backgrounds)
- **Medium Gray:** `#E5E7EB` (borders)
- **Dark Gray:** `#6B7280` (text secondary)
- **Text Dark:** `#111827` (primary text)
- **Success:** `#10B981` (positive actions)
- **Warning:** `#F59E0B` (attention)
- **Error:** `#EF4444` (destructive)
- **White:** `#FFFFFF` (cards, inputs)

### Typography

- **Headings:** System font stack (macOS/Windows optimized)
- **Body:** 14px-16px
- **Spacing:** 8px, 12px, 16px, 24px, 32px

### Components

- **Buttons:** Primary (blue), Secondary (outline), Outline, Danger
- **Cards:** White background, soft shadow, rounded corners
- **Inputs:** Clean borders, focus state with blue ring
- **Badges:** Inline labels with colors
- **Alerts:** Info (blue), Success (green), Warning (yellow), Danger (red)

---

## 📊 Navigation Structure

### Public (No Login)

```
Landing Page → Login/Sign Up
```

### After Signup

```
Profile Setup → Dashboard (role-based)
```

### Role-Specific Navigation

**Founder:**

```
Dashboard → Submit Idea
         → Submit Startup
         → My Ideas
         → Messages
         → Settings
```

**Advisor:**

```
Dashboard → Browse Ideas
         → My Reviews
         → Messages
         → Settings
```

**Investor:**

```
Dashboard → Browse Startups
         → My Portfolio
         → Saved Startups
         → Messages
         → Settings
```

**Admin:**

```
Admin Dashboard → User Verification
              → Reports & Moderation
              → Users
              → Ideas & Startups
              → Settings
```

---

## 🔄 User Flows

### New User Flow

1. Land on Homepage → See features
2. Click "Sign Up" → Sign Up Page
3. Enter details → Email verification
4. Profile Setup → Select role, add skills, write bio
5. Complete Profile → Access role-based dashboard

### Founder Idea Review Flow

1. Founder Dashboard → "Submit Idea" button
2. Founder Submit Idea page → Fill form
3. Select "Idea Review" mode → Submit
4. Post appears in Advisor dashboard
5. Advisors give feedback → Founder sees reviews

### Investor Investment Flow

1. Investor Dashboard → "Browse Startups"
2. See filtered startup list (investment posts only)
3. Click "View Details" → See full plan, team, traction
4. Click "Connect" → Opens chat with founder
5. Negotiate & invest

### Advisor Review Flow

1. Advisor Dashboard → See ideas needing review
2. Click "Review Idea" → View idea details
3. Rate idea (1-5 stars) → Add feedback
4. Optional: Contact founder for Q&A
5. Feedback appears publicly

---

## 📱 Responsive Design

**Breakpoints:**

- **Desktop:** 1024px+
- **Tablet:** 768px - 1023px
- **Mobile:** < 768px

**Mobile Adjustments:**

- Sidebar collapses/hidden
- Single column layouts
- Optimized touch targets (48px minimum)
- Simplified chat interface
- Accordion for filters

---

## 🚀 Quick Start

### File Structure

```
IdeaNest/
├── index.html              # Landing page
├── assets/
│   └── styles.css          # Global CSS (all screens)
└── pages/
    ├── login.html
    ├── signup.html
    ├── profile-setup.html
    ├── founder-dashboard.html
    ├── founder-submit-idea.html
    ├── founder-submit-startup.html
    ├── founder-ideas.html
    ├── advisor-dashboard.html
    ├── investor-dashboard.html
    ├── idea-details.html
    ├── chat.html
    └── admin-panel.html
```

### How to Use

1. **Open in browser:**
   - Start with `index.html`
   - Navigation links connect all pages

2. **Test Different Roles:**
   - Login → Select role in profile setup
   - Dashboard adjusts based on role
   - Try switching roles from top nav

3. **Feature Testing:**
   - Submit Idea → View in Advisor Dashboard
   - Submit Startup → View in Investor Dashboard
   - Check Chat, My Ideas, Admin panel

---

## ✨ Key Features Implemented

✅ Modern SaaS design (Notion/Stripe inspired)
✅ Strict role-based access control
✅ Two separate submission flows (Idea Review vs Investment)
✅ Advisors see ONLY review ideas
✅ Investors see ONLY investment posts
✅ Dynamic role switching with UI adaptation
✅ Profile completion restrictions
✅ Messenger-style chat system
✅ Admin moderation interface
✅ Responsive mobile design
✅ Clean spacing & professional typography
✅ Color-coded components & badges
✅ Interactive feedback forms
✅ Real-time chat simulation (JavaScript)
✅ Comprehensive filter systems

---

## 🎯 System Logic Enforcement

### Enforced Rules:

1. ✅ Users can ONLY be (Founder + Investor) OR (Advisor + Investor)
2. ✅ Incomplete profiles show "unlock features" warning
3. ✅ Advisors cannot see Investment posts
4. ✅ Investors cannot see Idea Review posts
5. ✅ Role switching completely changes dashboard layout
6. ✅ Each submission type has dedicated form (no mixing)
7. ✅ Admin panel separate access tier
8. ✅ Chat only between relevant pairs (Founder-Advisor, Founder-Investor)

---

## 📋 Notes for Figma Import

- All HTML files use semantic spacing (8px grid)
- Colors are consistent via CSS variables
- Components follow SaaS design patterns
- Ready for component library creation
- Easily exportable to Figma components
- Modern browser support (Chrome, Safari, Firefox, Edge)

---

## 🔒 Security Reminders

(For production implementation)

- Add email verification
- Implement OAuth 2.0 for Gmail login
- Hash passwords (bcrypt)
- CSRF token protection
- Rate limiting on API
- User role verification on server-side
- Input sanitization
- XSS protection

---

**Version:** 1.0 (Complete Design System)
**Last Updated:** 2024
**Design Style:** Modern SaaS (Notion/Stripe)
**Compatibility:** All modern browsers
